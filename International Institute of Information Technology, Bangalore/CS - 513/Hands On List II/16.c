#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    char buf1[80],buf2[80];
    int fd1[2],fd2[2];
    int a;
    int b;
    a=pipe(fd1);
    b=pipe(fd2);

    if(!fork())
    { //CHILD PROCESS
            close(fd1[0]);
            printf("\nenter msg to parent\n");
            scanf(" %[^\n]",buf1);
            write(fd1[1],buf1,sizeof(buf1));
            close(fd2[1]);
            read(fd2[0],buf2,sizeof(buf2));
            printf("\nmessage by parent = %s\n",buf2);
    }
    else
    { //PARENT PROCESS
      close(fd1[1]);
      read(fd1[0],buf1,sizeof(buf1));
      printf("\nmessage from child = %s\n",buf1);
      close(fd2[0]);
      printf("\nenter msg to child\n");
      scanf(" %[^\n]",buf2);
      write(fd2[1],buf2,sizeof(buf2));
    }
wait(0);
}
