// 26. Write a program to send messages to the message queue. Check $ipcs -q

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
  printf("\nEnter message: ");
  scanf("%s",mesg.buffer);
  msgsnd(id,&mesg,sizeof(mesg),0);
  // display the message
   printf("Data send is : %s \n", mesg.buffer);
  return 0;
}

/*
root@mohit-300E4Z-300E5Z-300E7Z:/proc/sys/fs/mqueue# ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x6107015a 0          mohit      666        6192         6
*/
