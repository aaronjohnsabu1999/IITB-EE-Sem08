#include<stdio.h>

__global__ void add(int *a, int *b, int *c)
{
  *c = *a + *b;
}

void main(int argc, char** argv)
{
  int a, b, c;
  int *dev_a, *dev_b, *dev_c;
  int size = sizeof(int);
  
  cudaMalloc((void**)&dev_a, size);
  cudaMalloc((void**)&dev_b, size);
  cudaMalloc((void**)&dev_c, size); // void** doesn't care the type of dev_x
  
  a = 2;
  b = 7;
  
  cudaMemcpy(dev_a, &a, size, cudaMemcpyHostToDevice);
  cudaMemcpy(dev_b, &b, size, cudaMemcpyHostToDevice);
  
  add<<<1,1>>>(dev_a, dev_b, dev_c);
  
  cudaMemcpy(&c, dev_c, size, cudaMemcpyDeviceToHost);
  
  cudaFree(dev_a);
  cudaFree(dev_b);
  cudaFree(dev_c);
  
  printf("%d", c);
  return 0;
}