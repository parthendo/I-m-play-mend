/*
 * Solution to copy content of one file to another
 * Author: MT2019074
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char* argv[]){

	if(argc != 3){
		write(1,"Not enough arguments found!\n",sizeof("Not enough arguments found!")+1);
	}
	else{
		const char* inp = (const char*)argv[1];
		const char* oup = (const char*)argv[2];
		int fd = open(inp,O_RDONLY);
		int fd1 = open(oup,O_WRONLY|O_CREAT);
		char c[0];
		while(write(fd1,c,read(fd,&c,1)));
	}
	return 0;
}
