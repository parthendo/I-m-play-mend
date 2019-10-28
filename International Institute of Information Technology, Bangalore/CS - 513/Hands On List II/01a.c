#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/time.h>
int main()
{
 struct itimerval val;
 val.it_interval.tv_sec=0;
 val.it_interval.tv_usec=0;
 val.it_value.tv_sec=10;
 val.it_interval.tv_usec=0;
 setitimer(ITIMER_REAL,&val,NULL);
 //sleep(11);
 return 0;
}
