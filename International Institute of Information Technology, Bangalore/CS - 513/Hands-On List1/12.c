/*
 * 12. Write a program to find out the opening mode of a file. Use fcntl.
 * Author: MT2019074
 */

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char const *argv[])
{
    if(argc != 2){
	printf("Too many/few argument");
    }
    else{
	const char* inp = (const char*)argv[1];
    	int fd = open(inp, O_CREAT|O_WRONLY|O_TRUNC, 0644);
    	char buffer_start[] = "Test message\nHello World";
    	write(fd, buffer_start, sizeof(buffer_start));
    	close(fd);

	fd = open(inp, O_RDONLY);
    	int open_mode = fcntl(fd, F_GETFL, 0)&O_ACCMODE;
    	if(open_mode == O_RDONLY)
        	printf("Read Only\n");
    	else if(open_mode == O_RDWR)
        	printf("Read Write\n");
    	else if(open_mode == O_WRONLY)
        	printf("Write Only\n");
    	else 
        	printf("Unknown access mode\n");
    	close(fd);
    }
    return 0;
}
