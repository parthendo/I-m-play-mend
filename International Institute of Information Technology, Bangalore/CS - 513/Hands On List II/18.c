#include<sys/types.h>
#include<signal.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
	int fd1[2],fd2[2];
	pipe(fd1);
  pipe(fd2);
	pid_t p=fork();
	if(p>0)
	{
		close(fd1[0]);
		dup2(fd1[1],STDIN_FILENO);
		close(fd2[0]);
		close(fd2[1]);
		execlp("ls","ls","-l",(char *)NULL);
	}
	else
	{
		pid_t t=fork();
		if(t>0)
		{
			dup2(fd1[0], STDIN_FILENO);
			dup2(fd2[1], STDOUT_FILENO);
			close(fd1[1]);
			close(fd2[0]);
			execlp("grep", "grep", "^d", (char *)NULL);
		}
		else
		{
			close(fd2[1]);
			dup2(fd2[0], STDIN_FILENO);
			close(fd1[0]);
			close(fd1[1]);
			execlp("wc", "wc", "-l", (char *)NULL);
		}
	}
}
