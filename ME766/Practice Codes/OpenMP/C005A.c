#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main()
{
    int myid, total;
    total = 0;
    
    #pragma omp parallel
    {
        myid = omp_get_thread_num();
        
        total += myid;
    }
    printf("\n total = %d", total);
    printf("\nProgram Exit!");
}