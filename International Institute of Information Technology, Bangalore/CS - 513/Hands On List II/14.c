#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
   int fd[2];
   pipe(fd);
   char buff[6];
   write(fd[1],"Hello",sizeof("Hello"));
   read(fd[0],buff,6);
   printf("The message is %s" ,buff);
}
