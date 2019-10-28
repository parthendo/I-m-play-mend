#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<signal.h>
void my_handler(int sig);
int main()
{
	int j;
	struct itimerval val;
	signal(SIGPROF,my_handler);
	printf("Catching SIGPROF\n");
	val.it_interval.tv_usec=0;
	val.it_interval.tv_sec=0;
	val.it_value.tv_usec=0;
	val.it_value.tv_sec=1;
	setitimer(ITIMER_PROF,&val,0);
	for(int i=0;i<1000000000;i++)
		j++;
	sleep(5);
	printf("SIGPROF not generated\n");
	return 0;
}
void my_handler(int sig)
{
	printf("SIGPROF caught, number=%d",sig);
	exit(0);
}
