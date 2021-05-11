#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int myid, num_thds, val;

int main()
{
    omp_set_num_threads(4);
    #pragma omp threadprivate(val)
    #pragma omp parallel
    {
        num_thds = omp_get_num_threads();
        myid = omp_get_thread_num();
        val = 50;
        printf("\nSection 1: From thread no. %d out of %d threads: value = %d", myid, num_thds, val);
    }
    printf("\n");
    #pragma omp parallel
    {
        myid = omp_get_thread_num();
        val = val + myid;
    }
    printf("\n");
    #pragma omp parallel
    {
        num_thds = omp_get_num_threads();
        myid = omp_get_thread_num();
        printf("\nSection 2: From thread no. %d out of %d threads: value = %d", myid, num_thds, val);
    }
    printf("\nProgram Exit!");
}