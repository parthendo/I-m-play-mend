#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
unsigned long long rdtsc()
{
	unsigned long long dst;
	__asm__  __volatile__("rdtsc":"=A"(dst));
	return dst;
}
int main()
{
	/*
	int pid=fork();
	if(pid==0)
	{
		printf("child Process id:%d",getpid());
		printf("parents process id using getppid() :%d",getppid());
	}
	else
	{
		printf("parents actual id : %d",getpid());
	}*/
	long long int start,end;
	//int pid=fork();
        int i=10,id;
	start=rdtsc();
	while(i>0)
	{
		id=getppid();
		i--;
	}
	end=rdtsc();
	printf("Difference is:%llu\n",end-start);
	return 0;
}
