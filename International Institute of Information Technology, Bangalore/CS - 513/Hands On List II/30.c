/*
30. Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
*/
#include<stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main(){
  char * s;
  key_t key;
  key=ftok(".",'a');
  int id=shmget(key, 1024, 0666 | IPC_CREAT);
  /* We now make the shared memory accessible to the program. */
   s = (char *)shmat(id, (void *)0, 0);
   /* read only shared memory*
    s = (char *)shmat(id, (void *)0, SHM_RDONLY);*/
   printf("Enter some text: ");
   scanf("%[^\n]%*c",s);
   while(s[0]!='*')
   sleep(1);
   // detached shared memory
   shmdt(s);
   //Remove shared memory
   shmctl(id, IPC_RMID, NULL);
 }
