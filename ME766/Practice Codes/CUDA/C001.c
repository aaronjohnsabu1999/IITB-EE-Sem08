#include<stdio.h>

__global__ void kernel(void)
{
  
}

void main(int argc, char** argv)
{
  kernel<<<1,1>>>();
  printf("Hello world\n");
  return 0;
}