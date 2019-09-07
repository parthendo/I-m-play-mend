/*
 * Write a program to display the environmental variable of the user (use environ).
 * Author: MT2019074
 */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

extern char **environ;
int main(int argc, char const *argv[])
{
    int count = 0;
    while(environ[count] != NULL)
    {
        printf("%s\n", environ[count]);
        count++;
    }
    return 0;
}
