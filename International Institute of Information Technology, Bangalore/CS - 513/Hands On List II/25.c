#include <stdio.h>
#include <sys/msg.h>
#include <sys/time.h>

struct ipc_perm msg_perm;
struct msqid_ds mq;

int main(){
	key_t key;
	int msgid;
	key = ftok(".",'p');
	msgid = msgget(key,0);
	msgctl(msgid,IPC_STAT,&mq);
	printf("Access Permission: %03o\n",mq.msg_perm.mode & 0777);
	printf("UID: %d\n", msg_perm.uid);
	printf("GID: %d\n", msg_perm.gid);
	printf("Time of last message received: %d\n",ctime(&mq.msg_rtime));
	printf("Time of last message sent: %d\n",ctime(&mq.msg_stime));
	printf("Time of last time change in message queue: %d\n",ctime(&mq.msg_ctime));
	printf("Size of the queue: %lu\n",mq.msg_cbytes);
	printf("Number of messages in the queue: %lu\n",mq.msg_qnum);
	printf("Maximum number of bytes allowed: %lu\n",mq.msg_qbytes);
	printf("PID of msgnd: %d & PID of msgrcv: %ld\n",mq.msg_lspid,mq.msg_lrpid);
}