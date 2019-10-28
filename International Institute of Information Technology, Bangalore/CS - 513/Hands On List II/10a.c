#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
void my_handler(int sig);
int main()
{
	struct sigaction val;
	val.sa_handler=my_handler;
	val.sa_flags=SA_RESTART;
	sigaction(SIGSEGV,&val,NULL);
	printf("Catching SIGSEGV\n");
	sleep(3);
	printf("No SIGSEGV in 3 seconds\n");
	return 0;
}
void my_handler(int sig)
{
	printf("SIGSEGV received,number=%d\n",sig);
	exit(0);
}
