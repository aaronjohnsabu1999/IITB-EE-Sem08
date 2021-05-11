#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main()
{
    int myid, total;
    total = 0;
    
    #pragma omp parallel private(myid) shared(total)
    {
        myid = omp_get_thread_num();
        
        #pragma omp atomic update
        total += myid;
    }
    printf("\n total = %d", total);
    printf("\nProgram Exit!");
}