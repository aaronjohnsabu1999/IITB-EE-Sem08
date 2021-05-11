#include<stdio.h>

__global__ void add(int *a, int *b, int *c)
{
  *c = *a + *b; // Host memory
}

void main(int argc, char** argv)
{
  kernel<<<1,1>>>();
  printf("Hello world\n");
  return 0;
}