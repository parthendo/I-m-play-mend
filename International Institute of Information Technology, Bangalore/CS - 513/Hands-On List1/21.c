/*
 * Fork to print PID of child and parent
 * Author: MT2019074
 */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){

	int x = fork();
	if(x == 0){
		printf("PID of child process is %d\n",getpid());
	}
	else{
		printf("PID of parent process is %d\n",getpid());
	}
	return 0;
}
