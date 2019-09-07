/*
 * 10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
 * a. check the return value of lseek
 * b. open the file with od and check the empty spaces in between the data.
 * Author: MT2019074
 */
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char const *argv[])
{
	if(argc != 2){
		printf("Too few/many arguments");	
	}
	else{
		int fd;
		char buffer1[1024] = "This is a test message\n";
		char buffer2[1024] = "Dummy message, doesn't mean anything\n";
		off_t lseek_cursor;
		ssize_t size_written;
		const char* str = (const char*)argv[1]; 
		fd = open(str, O_CREAT | O_RDWR| O_TRUNC, 0644);
		size_written = write(fd, buffer1, 10);
		printf("Moving file pointer by 10 bytes\n");
		lseek_cursor = lseek(fd, 10, SEEK_CUR);
		size_written = write(fd, buffer2, 10);
		printf("lseek returns %ld\n", lseek_cursor);
	}
	return 0;
}
