#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    char buf1[80],buf2[80];
    int fd1[2];
    int a;
    a=pipe(fd1);

    if(!fork())
    { //CHILD PROCESS
      close(fd1[1]);
      read(fd1[0],buf1,sizeof(buf1));
      printf("\nCHILD: \nmessage from parent = %s\n",buf1);
    }
    else
    { //PARENT PROCESS
      close(fd1[0]);
      printf("\nPARENT: \nenter msg to child\n");
      scanf(" %[^\n]",buf1);
      write(fd1[1],buf1,sizeof(buf1));

    }
wait(0);
}
