#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/time.h>
void my_handler(int sig);
int main()
{
	struct itimerval val;
	val.it_interval.tv_usec=0;
	val.it_interval.tv_sec=0;
	val.it_value.tv_usec=0;
	val.it_value.tv_sec=3;
	setitimer(ITIMER_REAL,&val,0);
	signal(SIGALRM,my_handler);
	printf("Catching SIGALRM\n");
	sleep(5);

}
void my_handler(int sig)
{
	printf("SIGALRM caught,number=%d",sig);
	exit(0);
}
