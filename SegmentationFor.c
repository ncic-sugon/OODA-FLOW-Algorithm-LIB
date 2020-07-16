#include <omp.h>
#include <stdio.h>
int main (){
int i, chunk,j=0;
float a[1000], b[1000], c[1000];
for (i=0; i < 1000; i++) /* 初始化 */
a[i] = b[i] = i * 1.0;
chunk =100;
#pragma omp parallel shared(a,b,c,chunk) private(i)
{
#pragma omp for schedule(dynamic,chunk) nowait
for (i=0; i <1000; i++)
c[i] = a[i] + b[i];
} /* end */
for (i=0; i <1000; i++)
{
printf("%f ",c[i]);
j++;
if(j%10==0)
 putchar('\n');
} /* end */
}
