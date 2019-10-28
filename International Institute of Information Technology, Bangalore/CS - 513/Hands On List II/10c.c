#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
void my_handler(int sig);
int main()
{
	struct sigaction val;
	val.sa_handler=my_handler;
	val.sa_flags=SA_RESTART;
	sigaction(SIGFPE,&val,NULL);
	printf("Catching SIGFPE\n");
	sleep(3);
	printf("SIGFPE not caught\n");
	return 0;
}
void my_handler(int sig)
{
 printf("SIGFPE caught,number=%d\n",sig);
 exit(0);
}
