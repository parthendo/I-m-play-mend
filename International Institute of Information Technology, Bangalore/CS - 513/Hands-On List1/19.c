/*
 * Program to find the execution time of getpid() system call
 * Author: MT2019074
 */
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc,char* argv[]){

	if(argc != 1){
		printf("Too many inputs\n");
		exit(1);
	}
	else{
		uint64_t x1 = rts();
		int x = getpid();
		uint64_t x2 = rts();
		printf("Time to execute pid() is %lfs\n",(double)x2-(double)x1);
	}
	return 0;
}
