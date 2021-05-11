#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int myid, num_thds, val;

int main()
{
    omp_set_num_threads(4);

    #pragma omp parallel
    {
        num_thds = omp_get_num_threads();
        myid = omp_get_thread_num();
        printf("\nFirst printf: %d out of %d threads", myid, num_thds);
        #pragma omp barrier
        printf("\nSecond printf: %d out of %d threads", myid, num_thds);
    }
    printf("\nProgram Exit!\n");
}