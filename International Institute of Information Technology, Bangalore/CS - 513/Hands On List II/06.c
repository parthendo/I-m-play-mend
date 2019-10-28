/*#include<pthread.h>
#include<stdio.h>
void sayHello(void)
{
	printf("Hello");
}
int main()
{
	pthread_t thread1,thread2,thread3;
	pthread_create(&thread1,NULL,(void *) sayHello,NULL);
	pthread_create(&thread2,NULL,(void *) sayHello,NULL);
	//printf("Hi");
	return 0;
}*/
#include <stdio.h>
#include <pthread.h>

/*thread function definition*/
void* newThread(void* args)
{
        printf("Thread Executed.\n");
}
int main()
{
    /*creating thread id*/
    pthread_t thread1,thread2,thread3;
    int ret;
    int i=10000000;
    /*creating thread*/
    pthread_create(&thread1,NULL,&newThread,NULL);
    pthread_create(&thread2,NULL,&newThread,NULL);
    pthread_create(&thread3,NULL,&newThread,NULL);
    while(i>0)
	    i--;
    printf("I am main function.\n");

    return 0;
}
