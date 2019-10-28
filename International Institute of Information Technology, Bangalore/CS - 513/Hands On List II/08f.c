#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<signal.h>
void my_handler(int sig);
int main()
{
	int i,j;
	struct itimerval val;
	val.it_interval.tv_usec=0;
	val.it_interval.tv_sec=0;
	val.it_value.tv_usec=0;
	val.it_value.tv_sec=1;
	setitimer(ITIMER_VIRTUAL,&val,0);
	signal(SIGVTALRM,my_handler);
	printf("Catching SIGVTALRM\n");
	for(int i=1;i<=1000000000;i++)
		j++;
	sleep(5);
	printf("SIVTALRM not generated\n");
	return 0;
}
void my_handler(int sig)
{
	printf("SIGVTALRM caught,number=%d",sig);
	exit(0);
}
