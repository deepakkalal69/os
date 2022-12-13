#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int sum;
void* runner(void* param);
int main(int argc,char* argv[])
{
pthread_t tid;
pthread_attr_t attr;
if(argc!=2){
printf("error");
return 1;
}
if(atoi(argv[1])<0){
printf("Number should be positive");
return 1; 
}
pthread_attr_init(&attr);
pthread_create(&tid,&attr,runner,argv[1]);
pthread_join(tid,NULL);
printf("sum=%d",sum);
}
void* runner(void* param)
{
int n=10,i;
sum=0;
n=atoi(param);
for(i=1;i<=n;i++){
sum=sum+i;
}
pthread_exit(0);
}

