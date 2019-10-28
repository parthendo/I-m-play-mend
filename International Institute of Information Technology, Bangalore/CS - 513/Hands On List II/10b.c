#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
void my_handler(int sig);
int main()
{
	struct sigaction val;
	val.sa_handler=my_handler;
	val.sa_flags=SA_RESTART;
	sigaction(SIGINT,&val,NULL);
	printf("CAtching SIGINT\n");
	sleep(3);
	printf("SIGINT not received\n");
	return 0;
}
void my_handler(int sig)
{
	printf("SIGINT caught , number=%d\n",sig);
	exit(0);
}
