#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	
	char buffer[100];
	int fd = open("22_fifo",O_NONBLOCK|O_RDONLY);
	fd_set fds;
	struct timeval tv;
	FD_ZERO(&fds);
	FD_SET(fd,&fds);
	tv.tv_sec = 10;
	if(select(4,&fds,NULL,NULL,&tv))
		printf("Reading message\n");
	else{
		printf("Timeout!\n");
		exit(0);
	}
	read(fd,buffer,sizeof(buffer));
	printf("Message read: %s\n", buffer);
	return 0;
}