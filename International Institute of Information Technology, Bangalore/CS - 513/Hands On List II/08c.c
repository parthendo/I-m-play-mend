#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void my_handler(int sig);
int main()
{
	signal(SIGFPE,my_handler);
	printf("Catching SIGFPE\n");
	sleep(3);
	printf("SIGFPE not received\n");
	return 0;
}
void my_handler(int sig)
{
	printf("I got SIGFPE,number=%d",sig);
	exit(0);
}
