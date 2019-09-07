/*
 * Duplicate file descriptor using fcntl
 * Author: MT2019074
 *
 * Open the duplicated and the original file after executing
 */
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc,char* argv[]){
	if(argc != 2){
		printf("Enter $./a.out file.txt");
	}
	else{
		const char * inp = (const char *)argv[1];
		int fd = open(inp,0666);
		int fd1 = fcntl(fd,F_DUPFD);
		write(fd,"Hello",strlen("Hello"));
		write(fd1,"Mello",strlen("Mello"));
	}
	return 0;
}
