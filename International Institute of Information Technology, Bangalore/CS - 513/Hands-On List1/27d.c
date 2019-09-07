#include<stdio.h>
#include<unistd.h>

extern char **environ;

int main(int argc, char const *argv[])
{
    char *const argument[] = {"ls", "-Rl", NULL}; 
    int execl_ = execv("/bin/ls", argument);
    perror("Error: ");
    printf("%d\n", execl_);
    return 0;
}
