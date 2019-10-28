//receiver side
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main()
{

	int fd,c=1;
	char buf[100];
	while(c)
	{
		fd=open("myfifo",O_RDONLY);
		read(fd,buf,sizeof(buf));
		write(STDOUT_FILENO,buf,strlen(buf));
		close(fd);
	}
}
