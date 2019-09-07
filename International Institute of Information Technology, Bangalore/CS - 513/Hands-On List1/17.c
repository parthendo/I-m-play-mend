/*
 * This program locks the file and allows only single user to enter at a time. 
 * Author: MT2019074
 * Execute 17createDB.c to create the database first. 
 * Open two terminals and try running 17.c on both of them simultaneously
 */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>


int main(){
	struct flock lock;
	struct{
		int ticket_no;
	}db;
	// Reading the database and setting lock params
	int fd = open("17db",O_RDWR);
	read(fd,&db,sizeof(db));
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	printf("Before entering into critical section\n");
	int x = fcntl(fd,F_SETLKW,&lock);
	// Loop for busy waiting
	// The same as above can be achieved by using F_SETLKW flag in the fcntl function
	/*while(x != 0){
		x = fcntl(fd,F_SETLK,&lock);
		printf("%d",x);
	}*/
	printf("Current ticket number %d\n",db.ticket_no);
	db.ticket_no++;
	lseek(fd,0L,SEEK_SET);
	printf("Inside the critical section\n");
	printf("Enter to unlock..\n");
	int l = write(fd,&db,sizeof(db));
	printf("%d\n",l);
	getchar();
	lock.l_type = F_UNLCK;
	printf("Unlocked\n");
	fcntl(fd,F_SETLK,&lock);
	printf("Fin!");
	return 0;
}
