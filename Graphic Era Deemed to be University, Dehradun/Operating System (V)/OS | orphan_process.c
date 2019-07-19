#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(){

	int PID = fork();
	if(PID>0){
		
		printf("Parent Executed ");
	}
	else if(PID == 0){
		
		sleep(10);
		printf("Child Executed ");
	}
	return 0;
}
