/*29. Write a program to remove the message queue.*/

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
  msgctl(id,IPC_RMID,NULL);
  return 0;
}


/*
------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x6107015a 65536      mohit      666        1032         1

root@mohit-300E4Z-300E5Z-300E7Z:/proc/sys/fs/mqueue# ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages

*/
