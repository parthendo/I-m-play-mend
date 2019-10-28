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
    close(1);
    close(fd[0]);
    fcntl(fd[1],F_DUPFD,1);
    execlp("ls","ls","-l",(char*)NULL);
  }
  else
  {
    close(0);
    close(fd[1]);
    fcntl(fd[0],F_DUPFD,0);
    execlp("wc","wc",(char*)NULL);
  }
}
