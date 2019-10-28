#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void my_handler(int sig);
int main()
{
	signal(SIGALRM,my_handler);
	printf("Catching SIGALRM\n");
	alarm(3);
	sleep(5);
	printf("SIGALRM not generated\n");
}
void my_handler(int sig)
{
	printf("SIGALRM received,number=%d\n",sig);
	exit(0);
}
