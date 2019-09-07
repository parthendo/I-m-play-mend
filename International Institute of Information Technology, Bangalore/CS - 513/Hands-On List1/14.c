/*
 * 14 Write a program to find the type of a file.
 * a. Input should be taken from command line.
 * b. program should be able to identify any type of a file.
 * Author: MT2019074
 */
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>

void quit(char *msg,int sts)
{
  perror(msg);
  exit(sts);
}

int main(int argc,char *argv[])
{
  DIR *dir;
  struct dirent *direntry;
  struct stat statbuf;
  mode_t file_type,file_perm;
  if((dir=opendir(argv[1]))==NULL)
  quit("Could not open directory\n",1);
  if((chdir(argv[1]))==-1)
  quit("chdir",2);

  while((direntry=readdir(dir))!=NULL)
  {
    if(lstat(direntry->d_name,&statbuf)<0)
    {
      perror("lstat");
      continue;
    }
    file_type=statbuf.st_mode&S_IFMT;
    file_perm=statbuf.st_mode&~S_IFMT;
    printf("type= %o perm= %4o name= %s\n",file_type,file_perm,direntry->d_name);
    if(S_ISREG(statbuf.st_mode))
      printf("File is regular file\n");
    if(S_ISDIR(statbuf.st_mode))
      printf("File is a directory\n");
    if(S_ISBLK(statbuf.st_mode))
      printf("File is a block special\n");
    if(S_ISCHR(statbuf.st_mode))
      printf("File is a character special\n");
    if(S_ISLNK(statbuf.st_mode))
      printf("File is a Symbolic link\n");
    if(S_ISFIFO(statbuf.st_mode))
      printf("File is a FIFO\n");
    if(S_ISSOCK(statbuf.st_mode))
      printf("File is a socket\n");
  }
  return 0;
}
