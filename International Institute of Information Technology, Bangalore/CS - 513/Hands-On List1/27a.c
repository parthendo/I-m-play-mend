/*
 * Author: MT2019074
 */
#include<stdio.h>
#include<unistd.h>

extern char **environ;

int main(int argc, char const *argv[])
{
    int execl_ = execl("/bin/ls", "ls", "-Rl", (char *)NULL);
    perror("Error: ");
    printf("%d\n", execl_);
    return 0;
}
