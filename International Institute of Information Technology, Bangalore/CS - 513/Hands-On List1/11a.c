/*
 * Solution to use library function dup()
 * Author: MT2019074
 */
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc,char* argv[]){

	if(argc!=2){
		write(1,"Not enough arguments found!\n",sizeof("Not enough arguments found!")+1);
	}
	else{
		const char* inp = (const char*)argv[1];
		int fp = open(inp,O_WRONLY|O_CREAT);
		int fp1 = dup(fp);
		write(fp,"Message 1",strlen("Message 1"));
		write(fp1,"Message 2",strlen("Message 2"));
	}
	return 0;
}
