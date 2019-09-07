/*
 * Program to demonstrate a zombie process.
 * Author: MT2019074
 * Compile and run program in the background
 * $ps aux
 * <defunc> process is the zombie one
 */

#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(){

	int PID = fork();
	if(PID>0){
		
		sleep(50);
	}
	else{
		
		exit(0);
	}
	return 0;
}
