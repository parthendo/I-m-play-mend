#include<stdio.h>
#include<unistd.h>

extern char **environ;

int main(int argc, char const *argv[])
{
    int execl_ = execlp("/bin/ls", "ls", "-Rl", (char *)NULL);
    printf("%d\n", execl_);
    return 0;
}
