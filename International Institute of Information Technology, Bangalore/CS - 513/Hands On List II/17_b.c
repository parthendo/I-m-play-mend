#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
  int fd[2];
  pipe(fd);
  if(!fork())
  {
    close(fd[0]);
    dup2(fd[1],1);
    execlp("ls","ls","-l",(char*)NULL);
  }
  else
  {
    close(fd[1]);
    dup2(fd[0],0);
    execlp("wc","wc",(char*)NULL);
  }
}
