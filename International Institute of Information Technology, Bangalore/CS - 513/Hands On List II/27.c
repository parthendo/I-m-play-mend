/*27. Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int main() {
  struct mesg{
    long int mtype;
    char buffer[1024];
  }mesg;
  key_t key;
  int id;
   // ftok to generate unique key
  key=ftok(".",'a');
  id = msgget(key, 0666 | IPC_CREAT);
  printf("Enter message type :");
  scanf("%ld",&mesg.mtype);
  msgrcv(id,&mesg,sizeof(mesg),mesg.mtype,0);
  // display the message
   printf("Data receive is : %s \n", mesg.buffer);
  return 0;
}
/*
------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x6107015a 32768      mohit      666        2064         2

root@mohit-300E4Z-300E5Z-300E7Z:/proc/sys/fs/mqueue# ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x6107015a 32768      mohit      666        1032         1
*/
