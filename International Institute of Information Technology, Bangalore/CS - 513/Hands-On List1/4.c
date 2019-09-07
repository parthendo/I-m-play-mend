/*
 * Try O_EXCL
 * Author: MT2019074
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){

	int fd = open("4tst.txt",O_CREAT|O_WRONLY,0644);
	write(fd,"This is a temporary file",sizeof("This is a temporary file"));
	close(fd);
	fd = open("4tst.txt",O_CREAT|O_RDONLY|O_EXCL,0644);
	if(fd == -1)
		printf("FIle already exists");
	return 0;
}
