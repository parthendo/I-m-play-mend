/*
 * Program to make 5 new files and an infinite loop
 * Author: MT2019074
 */
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){

	int fd1 = open("5_1.txt",O_CREAT|O_WRONLY,0644);
	int fd2 = open("5_2.txt",O_CREAT|O_WRONLY,0644);
	int fd3 = open("5_3.txt",O_CREAT|O_WRONLY,0644);
	int fd4 = open("5_4.txt",O_CREAT|O_WRONLY,0644);
	int fd5 = open("5_5.txt",O_CREAT|O_WRONLY,0644);
	getchar();
	return 0;
}
