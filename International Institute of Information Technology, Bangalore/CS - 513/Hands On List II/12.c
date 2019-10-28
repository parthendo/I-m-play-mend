#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int pid = fork();
    if (pid > 0){
      printf("in parent process\n");
      sleep(30);
    }



    else if (pid == 0)
    {
        sleep(10);
        printf("in child process\n");
        int r=getppid();//get parent's process id
        int k=kill(r,9);// give SIGKILL sognal to  parent process
        printf("%d",k);// returns 1 if killed

    }

    return 0;
}
