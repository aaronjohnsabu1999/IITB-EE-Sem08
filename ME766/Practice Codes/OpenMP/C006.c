#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main()
{
    int myid, num_thds;
    int data = 10;
    
    omp_set_num_threads(4);
    
    #pragma omp parallel private(myid, num_thds) firstprivate(data)
    {
        myid = omp_get_thread_num();
        data = data + myid;
        
        printf("\nFrom thread no. %d out of %d threads: data = %d", myid, num_thds, data);
    }
    printf("\n data = %d", data);
    printf("\nProgram Exit!");
}