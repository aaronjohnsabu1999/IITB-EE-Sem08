#include"stdio.h"
#include"omp.h"
int main()
{
    #pragma omp parallel
    {
        printf("\nHello World!");
    }
    printf("\nProgram Exit!");
    return 0;
}