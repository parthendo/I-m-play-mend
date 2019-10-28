#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
int main()
{
	signal(SIGINT,SIG_IGN);
	printf("Ignoring SIGINT\n");
	sleep(3);
	printf("No SIGINT within 3 sec\n");
	signal(SIGINT,SIG_DFL);
	printf("Default action for SIGINT\n");
	sleep(3);
	printf("NO SIGINT within 3 sec\n");
	return 0;
}
