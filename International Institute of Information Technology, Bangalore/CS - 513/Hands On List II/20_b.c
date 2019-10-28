//sender side
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
	char buff[100];
	ssize_t size;
	while(c)
	{
		fd=open("myfifo",O_WRONLY);
		size=read(STDIN_FILENO,buff,sizeof(buff));
		buff[size]='\0';
		write(fd,buff,strlen(buff) + 1);
		close(fd);
    printf("\n for more press 1 else press 0 \n");
  scanf("%d",&c);
	}
}
