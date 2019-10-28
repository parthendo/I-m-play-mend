#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>
#include<stdlib.h>
int main()
{
	struct rlimit old,curr,new_limit;
	curr.rlim_cur=5;
	curr.rlim_max=2048;
	if(setrlimit(RLIMIT_NOFILE,&curr));
	if(getrlimit(RLIMIT_NOFILE,&new_limit)==0)
	{
		printf("New limits are: \n rlim_cur=%ld \t rlim_max=%ld",new_limit.rlim_cur,new_limit.rlim_max);
	}
}
