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

int create_connection(){
	char buffer[1024];
	int listenfd = 0;
	struct sockaddr_in serv_addr;

	listenfd = socket(AF_INET,SOCK_STREAM,0);
	if(listenfd == -1){
		printf("Error: Unable to establish connection. Try again later!\n");
		return 0;
	}
	else{
    	bzero(&serv_addr,sizeof(serv_addr));
    	int port = 5050;
		serv_addr.sin_family = AF_INET;
    	serv_addr.sin_port = htons(port);
    	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    	return listenfd;
	}
}
int main(){
	char buffer[2000];
	int sockfd,listenfd = create_connection();
	listen(listenfd,10);
	while(1){
		sockfd = accept(listenfd,(struct sockaddr*)NULL,NULL);
		if(sockfd == -1){
			printf("Error\n");
			exit(1);
		}
		else{
			if(fork() == 0){
				close(listenfd);
				while(1){
					read(sockfd,buffer,1024);
					printf("Message from client: %s\n",buffer);
					printf("Type Message: ");
					scanf("%s",buffer);
					if(strcmp(buffer,"quit") == 0){
						close(sockfd);
						break;
					}
					write(sockfd,buffer,sizeof(buffer));
				}
			}
		}
	}
	return 0;
}