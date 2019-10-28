#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void my_handler(int sig);
int main()
{
	signal(SIGINT,my_handler);
	printf("Catching SIGINT\n");
	sleep(3);
	printf("No SIGINT wihtin 3 seconds");
	return 0;
}
void my_handler(int sig)
{
	printf("Got SIGINT,number%d\n",sig);
	exit(0);
}
