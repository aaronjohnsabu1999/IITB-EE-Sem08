#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

#define ARRSIZE 20000

int main()
{
    int myid, size;
    int i;
    int *A, *B, *C;
    
    A = (int *)malloc(ARRSIZE*sizeof(int));
    B = (int *)malloc(ARRSIZE*sizeof(int));
    C = (int *)malloc(ARRSIZE*sizeof(int));
    
    for (i=0; i<ARRSIZE; i++)
    {
        A[i] = i;
        B[i] = i;
    }
    
    #pragma omp parallel for
    for (i=0; i<ARRSIZE; i++)
    {
        C[i] = A[i] + B[i];
    }
    
    return 0;
}