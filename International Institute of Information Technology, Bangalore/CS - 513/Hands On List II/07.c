#include<pthread.h>
#include<stdio.h>
void* printId(void *args)
{
	printf("Current Thread Id is:%d\n",pthread_self());
}
int main()
{
 pthread_t thread1,thread2,thread3;
 pthread_create(&thread1,NULL,&printId,NULL);
 pthread_create(&thread2,NULL,&printId,NULL);
 pthread_create(&thread3,NULL,&printId,NULL);
 int i=10000000;
 while(i>0)
	 i--;
 printf("main() function ends");
 return 0;
}
