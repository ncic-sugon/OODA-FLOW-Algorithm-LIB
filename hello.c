#include <omp.h>
#include <stdio.h>
int main()
{
int myid, numthreads;
omp_set_num_threads(4);
#pragma omp parallel
{
myid = omp_get_thread_num();
numthreads = omp_get_num_threads();
printf("Hello World from thread %d of %d!\n",myid,numthreads);
}
}
