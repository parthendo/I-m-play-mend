/*
 * 18. Write a program to perform Record locking.
 * a. Implement write lock
 * b. Implement read lock
 * Create three records in a file. Whenever you access a particular record, first lock it then modify/access to avoid race condition. 
 * 
 * Data Set:
 * 1 abcdefgh
 * 2 ijklmnop
 * 3 prrstuvw
 *
 * Author: MT2019074
 */

#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main()
{
  struct flock lock;
  int fd,n;
  fd=open("db",O_RDWR);
  lock.l_type=F_RDLCK;

  lock.l_whence=SEEK_CUR;
  printf("Enter choice of record 1,2,3\n");
  scanf("%d",&n);
  lock.l_start=(n-1)*10;
  lock.l_len=9;
  lock.l_pid=getpid();
  printf("Before entering into critical section and taking read lock\n");
  fcntl(fd,F_SETLKW,&lock);
  printf("Inside critical section \n");
  char buff[9];
  lseek(fd,(n-1)*10,SEEK_SET);
  read(fd,buff,9);
  write(1,buff,strlen(buff));
  printf("\npress enter to unlock \n");
  getchar();
  getchar();
  lock.l_type=F_UNLCK;
  fcntl(fd,F_SETLK,&lock);
  printf("Unlocked read \n");
  printf("Finished\n");
  return(0);

}
