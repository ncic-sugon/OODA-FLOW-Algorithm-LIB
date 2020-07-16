#include <omp.h>
#include <stdio.h>
int main ()
{
int i,j=0;
float a[1000], b[1000], c[1000];
for (i=0; i < 1000; i++) /* 初始化 */
a[i] = b[i] = i * 1.0;
#pragma omp parallel shared(a,b,c) private(i)
{
#pragma omp sections nowait
{
#pragma omp section
for (i=0; i < 500; i++) c[i] = a[i] + b[i];
#pragma omp section
for (i=500; i < 1000; i++) c[i] = a[i] * b[i];
} /* end of sections */
}
for(i=0;i<1000;i++)
{
 printf("%f ",c[i]);
j++;
if(j%10==0)
 putchar('\n');
}
}
