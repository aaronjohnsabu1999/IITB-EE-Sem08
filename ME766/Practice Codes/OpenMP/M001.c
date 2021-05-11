#include<stdio.h> 
#include<omp.h> 

void integration(int numSteps)
{
  int i, nthread, numThreads;
  double x, pi, sum = 0.0, step;
  double arr[4]={0,0,0,0};
  step = 1.0/numSteps;
  
  omp_set_num_threads(4);
  #pragma omp parallel private(nthread, x)
  {
    nthread    = omp_get_thread_num();
    numThreads = omp_get_num_threads();
    x = nthread * step;
    i = 0;
    while (x < 1)
    {
      x += step*numThreads;
      arr[nthread] = arr[nthread] + 4.0/(1+x*x);
    }
  }
  pi = (arr[0]+arr[1]+arr[2]+arr[3])*step;
  printf("%d steps: I = %f \n", numSteps, pi);
}

int main()
{
  for (int numSteps = 2; numSteps <= 100000; numSteps *= 1.5)
  {
    integration(numSteps);
  }
  return 0;
}