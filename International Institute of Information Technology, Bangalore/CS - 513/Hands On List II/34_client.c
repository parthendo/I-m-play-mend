#include <stdio.h>
#include <math.h>
#include <sys/socket.h> 
#include <netdb.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h> 

int create_connection(char* IP){
	int socketfd, connfd;
	struct sockaddr_in servaddr,cli;
	socketfd = socket(AF_INET,SOCK_STREAM,0);
	if(socketfd == -1){
		printf("Error: Unable to establish connection. Try again later!\n");
		return 0;
	}
	else{
    	bzero(&servaddr,sizeof(servaddr));
		servaddr.sin_family = AF_INET; 
    	servaddr.sin_addr.s_addr = inet_addr((const char*)IP); 
    	int flag,port = 5050;
		servaddr.sin_port = htons(port); 
		connect(socketfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
		flag = 1;
		if(!flag){
			printf("Error: Connection with server failed. Try again later!\n");
			return 0;
		}
		else{
			printf("Success message: Connection established successfully on port %d!\n",port);
			return socketfd; 
		}
	}
}

int main(){
	char buffer[2000];
	int socketfd = create_connection("127.0.0.1");
	while(1){
		printf("Type message: ");
		scanf("%s",buffer);
		if(strcmp(buffer,"quit") == 0){
			break;
		}
		write(socketfd,buffer,1024);
		read(socketfd,buffer,1024);
		printf("Message from server: %s\n",buffer);
	}
	return 0;
}