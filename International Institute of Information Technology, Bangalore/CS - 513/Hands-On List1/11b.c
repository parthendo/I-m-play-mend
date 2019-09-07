/*
 * Solution to system call dup2()
 * Author: MT2019074
 */
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){

	if(argc!=2){
		write(1,"Not enough arguments found!\n",sizeof("Not enough arguments found!")+1);
	}
	else{
		const char* inp = (const char*)argv[1];
		int fp= open(inp,O_WRONLY|O_CREAT);
		write(fp,"This is a new file\n",strlen("This is a new file\n"));
		dup2(fp,1);
		write(fp,"This is testing\n",strlen("This is testing\n"));
	}
	return 0;
}
