#include"stdio.h"
#include"omp.h"
int main()
{
    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            printf("\nHello World!");
            #pragma omp section
            printf("\nWhat's up?");
        }
    }
    printf("\nProgram Exit!");
    return 0;
}