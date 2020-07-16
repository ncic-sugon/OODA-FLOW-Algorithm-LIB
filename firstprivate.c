#include <omp.h>
#include <stdio.h>
main(){
int i,sum=0,myid;
#pragma omp parallel for firstprivate(sum)
for(i=0;i<10;i++){
sum = sum + 1;
printf("%d\n",sum);
}
printf("sum = %d\n",sum);
}
