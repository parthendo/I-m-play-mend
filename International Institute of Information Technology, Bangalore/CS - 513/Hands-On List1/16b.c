/*
 * 16. Write a program to perform mandatory locking.
 * a. Implement write lock
 * b. Implement read lock
 * Author: MT2019074
 */

#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
  struct flock lock;
  int fd;
  fd=open("db",O_RDWR);
  lock.l_type=F_RDLCK;
  lock.l_whence=SEEK_SET;
  lock.l_start=0;
  lock.l_len=0;
  lock.l_pid=getpid();
  printf("Before entering into critical section and taking write lock \n");
  fcntl(fd,F_SETLKW,&lock);
  printf("Inside critical section \n");
  printf("Press Enter to Unlock \n");
  getchar();
  lock.l_type=F_UNLCK;
  fcntl(fd,F_SETLK,&lock);
  printf("Unlocked write \n");
  printf("Finished\n");
  return(0);
}
