/*
 * Solution to read file and print line-by-line
 * Author: MT2019074
 */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	
	if(argc != 2){
		write(1,"Not enough arguments found!\n",sizeof("Not enough arguments found!")+1);
	}
	else{
		const char* inp = (const char*)argv[1];
		int fd = open(inp,O_RDONLY);		
		char buff[10005];
		int i=0;
		int line = 0;
		char c[0];
		while(read(fd,&c,1)){
			if(c[0] == '\n'){
				buff[i] = '\0';
				i = 0;
				printf("Line %d: %s\n",++line,buff);	
			}
			else{
				buff[i++] = c[0];
			}
		}
	}
	return 0;
}
