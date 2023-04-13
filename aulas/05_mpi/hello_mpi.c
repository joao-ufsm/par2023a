#include <stdio.h>
#include <mpi.h>

int main(void)
{
  int rank, comm_size;
  MPI_Init(NULL, NULL);

  MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  printf ("Hello from process %d of %d!\n", rank, comm_size);

  MPI_Finalize();
  return 0;
}