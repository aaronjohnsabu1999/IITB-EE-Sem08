#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

#define ARRSIZE 10
int i, sum, A[ARRSIZE];

int main()
{
    omp_set_num_threads(4);
    
    for (i=0; i<ARRSIZE; i++)
    {
        A[i] = i;
    }
    
    #pragma omp parallel for default(none) shared(A) reduction(+:sum)
    for (i=0; i<ARRSIZE; i++)
    {
        sum = sum + A[i];
    }
    printf("Sum = %d\n", sum);
    
    #pragma omp parallel for
    for (i=0; i<ARRSIZE; i++)
    {
        sum = sum + A[i];
    }
    printf("Sum = %d\n", sum);
}