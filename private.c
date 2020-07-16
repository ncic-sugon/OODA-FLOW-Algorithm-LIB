#include<omp.h>
#include<stdio.h>
main(){
int i,sum=0,myid;
#pragma omp parallel for private(i,sum)
for(i=0;i<10;i++){
myid = omp_get_thread_num();
printf("%d\n",myid);
sum = sum + 1;
printf("%d\n",sum);
}
printf("sum = %d\n",sum);
}
