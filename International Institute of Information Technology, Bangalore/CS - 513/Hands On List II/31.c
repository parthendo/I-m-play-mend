/*
31. Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
b. create a counting semaphore
*/
#include <stdio.h>
#include <sys/sem.h>
 union semun {
 int val;
 unsigned short int *array;
 }arg;

 int  main() {
   int key,semid,i,ret;
   static ushort semarray[2]={1,2};
   key=ftok(".",'m');
   semid=semget(key,2,IPC_CREAT|0744);
   arg.array=semarray;
   semctl(semid,0,SETALL,arg);
   for(i=0;i<2;i++){
     ret=semctl(semid,i,GETVAL,0);
     printf("Sem %d=%d\n",i,ret);
   }
 }
