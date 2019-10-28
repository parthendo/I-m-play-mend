#include<stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
int main()
{
	struct rlimit rlim;
	if(getrlimit(RLIMIT_NOFILE,&rlim)==0)
		printf("rlim_cur=%ld \t rlim_max=%ld\n",rlim.rlim_cur,rlim.rlim_max);
	return 0;
}
