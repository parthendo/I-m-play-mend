/*
 * C program to create a file and return the file descriptor
 * Author: MT2019074
 */
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc,char* argv[]){
	if(argc != 2){
		printf("Enter only the file name or the path of the file\n"); 
	}
	else{
		const char * str = argv[1];
		int fd = creat(str,0744);
		perror(" ");
		printf("The file descriptor of the file is %d\n",fd);
	}
	return 0;
}

