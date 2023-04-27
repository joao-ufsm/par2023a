/*
Fractal code for CS 4380 / CS 5351

Copyright (c) 2018, Texas State University. All rights reserved.

Redistribution and usage in source and binary form, with or without
modification, is only permitted for educational use.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

Author: Martin Burtscher
*/

#include <cstdlib>
#include <sys/time.h>
#include "fractal.h"

#include "mpi.h"

static const double Delta = 0.001;
static const double xMid =  0.23701;
static const double yMid =  0.521;

void mandel_serial(unsigned char* buffer, 
    const int local_row, const int width)
{
  // compute frames
  double delta = Delta;
  const double xMin = xMid - delta;
  const double yMin = yMid - delta;
  const double dw = 2.0 * delta / width;
//  for (int row = 0; row < local_width; row++) {
  const double cy = yMin + local_row * dw;
  for (int col = 0; col < width; col++) {
    const double cx = xMin + col * dw;
    double x = cx;
    double y = cy;
    int depth = 256;
    double x2, y2;
    do {
      x2 = x * x;
      y2 = y * y;
      y = 2 * x * y + cy;
      x = x2 - y2 + cx;
      depth--;
    } while ((depth > 0) && ((x2 + y2) < 5.0));
    buffer[col] = (unsigned char)depth;
  }
//  }
}

int main(int argc, char *argv[])
{
  printf("Fractal v1.6 [serial]\n");

  // check command line
  if (argc != 2) {fprintf(stderr, "usage: %s width\n", argv[0]); exit(-1);}
  int width = atoi(argv[1]);
  if (width < 10) {fprintf(stderr, "error: frame_width must be at least 10\n"); exit(-1);}

  int my_rank;
  int comm_sz;
  MPI_Init(NULL, NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);

  // total de tarefas geradas com o grao
  //int total_tasks = width / grain;
  // start time
  timeval start, end;
  gettimeofday(&start, NULL);

  unsigned char* pic = nullptr;
  MPI_Status status;
  if(my_rank == 0){
    int rows_send = 0;     // linhas enviadas 
    int rows_waiting = 0;  // quantos espera resposta
    pic = new unsigned char[width * width];
    unsigned char* buffer = new unsigned char[width];

    // envia as primeiras tarefas ao processos
    for(int dest = 1; (dest < comm_sz) && (rows_send < width); dest++){
      MPI_Send(&rows_send, 1, MPI_INT, dest, 0, MPI_COMM_WORLD);
      rows_send++;
      rows_waiting++;
    }

    do{  
      // recebe uma mensagem qualquer de um worker
      MPI_Recv(buffer, 
            width, MPI_UNSIGNED_CHAR, 
            MPI_ANY_SOURCE, MPI_ANY_TAG,
            MPI_COMM_WORLD, &status);
      rows_waiting--;

      // copia os dados para o buffer principal
      int row = status.MPI_TAG;
      memcpy( &pic[row*width], buffer, width*sizeof(unsigned char) );

      // ainda tem trabalho para enviar ?
      if(rows_send < width){
        MPI_Send(&rows_send, 1, MPI_INT, status.MPI_SOURCE, 0, MPI_COMM_WORLD);
        rows_send++;
        rows_waiting++;
      }else // manda o worker terminar com tag -1
        MPI_Send(&rows_send, 1, MPI_INT, status.MPI_SOURCE, 99, MPI_COMM_WORLD);
    } while(rows_waiting > 0);
  } else {
    // workers precisam apenas de um pedaco
    unsigned char* buffer = new unsigned char[width];
    int local_row = 0;
    MPI_Recv(&local_row, 1, MPI_INT, 
            0, MPI_ANY_TAG,
            MPI_COMM_WORLD, &status);    
    // enquanto a tag significa "trabalho"
    while( status.MPI_TAG == 0 ){
      mandel_serial( buffer, local_row, width );
      MPI_Send(buffer, width, MPI_UNSIGNED_CHAR, 0, local_row, MPI_COMM_WORLD);       
      // recebemos outro trabalho ?
      MPI_Recv(&local_row, 1, MPI_INT, 
            0, MPI_ANY_TAG,
            MPI_COMM_WORLD, &status);       
    }
  }

  // end time
  gettimeofday(&end, NULL);
  double runtime = end.tv_sec + end.tv_usec / 1000000.0 - start.tv_sec - start.tv_usec / 1000000.0;
  printf("compute time: %.4f s\n", runtime);

  // verify result by writing frames to BMP files
  if ((my_rank == 0) && (width <= 8192)) {
    char name[32];
    sprintf(name, "fractal%d.bmp", width);
    writeBMP(width, width, pic, name);
 
  }

  MPI_Finalize();
  delete [] pic;   

  return 0;
}
