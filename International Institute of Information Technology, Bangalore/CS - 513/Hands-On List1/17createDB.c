/*
 * This program creates a database with a default ticket number. 
 * This structure can later be extended and multiple values can be stored in the set.
 * Author: MT2019074
 */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
	
	int fd;
	struct{
		int ticket_no;
	}db;
	db.ticket_no = 10;
	fd = open("17db",O_CREAT|O_RDWR,0744);
	write(fd,&db,sizeof(db));
	close(fd);
	fd = open("17db",O_RDONLY);
	read(fd,&db,sizeof(db));
	printf("Ticket Number %d\n",db.ticket_no);
	return 0;
}
