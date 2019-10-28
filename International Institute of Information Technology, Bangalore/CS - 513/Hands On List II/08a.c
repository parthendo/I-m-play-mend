#include<signal.h>
#include<stdlib.h>
#include<stdio.h>
void my_handler(int sig);
int main(void)
{
	signal(SIGSEGV,my_handler);
	printf("Catching SIGSEGV\n");
	sleep(3);
	printf("No SIGSEGV within 3 seconds\n");
	return 0;
}
void my_handler(int sig)
{
	printf("I got SIGSEGV,number %d\n",sig);
	exit(0);
}
