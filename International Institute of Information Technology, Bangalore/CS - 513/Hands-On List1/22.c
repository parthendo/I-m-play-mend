/*
 * Program to see the working of parent and child on same file.
 * Author: MT2019074
 * Output: Line printed by parentAnother line printed by parentLine printed by childAnother line printed by child
 */
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc,char* argv[]){
	if(argc!=2){
		printf("Too many/few arguments\n");
		exit(1);
	}
	else{
		const char* inp = (const char*)argv[1];
		int fd = creat(inp,0664);
		int x = fork();
		//Refrain from using \n as it clears the buffer
		if(x == 0){
			write(fd,"Line printed by child",sizeof("Line printed by child"));
			write(fd,"Another line printed by child",sizeof("Another line printed by child"));
		}
		else{
			write(fd,"Line printed by parent",sizeof("Line printed by parent"));
			write(fd,"Another line printed by parent",sizeof("Another line printed by parent"));
		}
	}
	return 0;
}
