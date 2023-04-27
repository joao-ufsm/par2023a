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

void mandel_serial(unsigned char* pic, 
    const int local_width, const int my_rank, const int width)
{
  // iniciamos na linha do processo atual
  const int local_row = my_rank * local_width;
  
  // compute frames
  double delta = Delta;
  const double xMin = xMid - delta;
  const double yMin = yMid - delta;
  const double dw = 2.0 * delta / width;
  for (int row = 0; row < local_width; row++) {
    const double cy = yMin + (row + local_row) * dw;
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
      pic[row * width + col] = (unsigned char)depth;
    }
  }
}

int main(int argc, char *argv[])
{
  printf("Fractal v1.6 [parallel]\n");

  // check command line
  if (argc != 2) {fprintf(stderr, "usage: %s width\n", argv[0]); exit(-1);}
  int width = atoi(argv[1]);
  if (width < 10) {fprintf(stderr, "error: frame_width must be at least 10\n"); exit(-1);}


  int my_rank;
  int comm_sz;
  MPI_Init(NULL, NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);

  // divide as linhas do fractal entre processos
  int local_width = width / comm_sz;
  // start time
  timeval start, end;
  gettimeofday(&start, NULL);


  unsigned char* pic = nullptr;
  if(my_rank == 0){
    pic = new unsigned char[width * width];
    mandel_serial( pic, local_width, 0, width );
    for (int source = 1; source < comm_sz; source++) {
        MPI_Recv(&pic[source*local_width*width], 
          local_width*width, MPI_UNSIGNED_CHAR, 
          source, 0,
          MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
  } else {
    // workers precisam apenas de um pedaco
    unsigned char* pic = new unsigned char[local_width * width];
    mandel_serial( pic, local_width, my_rank, width );
    MPI_Send(pic, local_width*width, MPI_UNSIGNED_CHAR, 0, 0, MPI_COMM_WORLD);       
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
