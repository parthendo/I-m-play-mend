/*
28. Write a program to change the exiting message queue permission. (use msqid_ds structure)
*/
#include <stdio.h>
#include<sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int get_queue_ds( int qid, struct msgqid_ds *qbuf ){
        if( msgctl( qid, IPC_STAT, qbuf) == -1){
                return(-1);
        }
        return(0);
}
int change_queue_mode( int qid, char *mode ){
        struct msqid_ds tmpbuf;
        get_queue_ds( qid, &tmpbuf);
        printf("before change the mode of message queue: ");
        printf("Access mode in HEX \t%06X\n", tmpbuf.msg_perm.mode);
        /* Change the permissions using an old trick */
        sscanf(mode, "%ho", &tmpbuf.msg_perm.mode);
        /* Update the internal data structure */
        if( msgctl( qid, IPC_SET, &tmpbuf) == -1){
                return(-1);
        }
        get_queue_ds( qid, &tmpbuf);
        printf("After change the mode of message queue: ");
        printf("Access mode in HEX \t%06X\n", tmpbuf.msg_perm.mode);

        return(0);
}
int main() {
  struct mesg{
    long int mtype;
    char buffer[1024];
  }mesg;
  key_t key;
  int id;
   // ftok to generate unique key
  key=ftok(".",'a');
  id = msgget(key, 0644|IPC_CREAT|IPC_EXCL);
  change_queue_mode(id,"0666");
  return 0;
}
