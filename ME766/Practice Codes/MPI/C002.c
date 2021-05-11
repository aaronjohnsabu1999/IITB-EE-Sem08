#include<stdio.h>
#include "mpi.h"

void main(int argc, char** argv)
{
  int my_PE_num, numSend = 8, numRecv;
  MPI_Status status;
  
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_PE_num);
  if (my_PE_num == 0)
  {
    MPI_Recv(&numRecv, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
    printf("Number received on %d is: %d\n", my_PE_num, numRecv);
  }
  else
  {
    MPI_Send(&numSend, 1, MPI_INT, 0, 10,  MPI_COMM_WORLD);
    printf("Number sent from %d is: %d\n", my_PE_num, numSend);
  }
  MPI_Finalize();
}