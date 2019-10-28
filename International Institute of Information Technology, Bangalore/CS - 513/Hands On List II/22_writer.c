#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(){
	char buffer[100];
	int fd = open("22_fifo",O_WRONLY);
	printf("Enter the message to FIFO: ");
	scanf("%[^\n]",buffer);
	write(fd,buffer,sizeof(buffer));
	return 0;
}