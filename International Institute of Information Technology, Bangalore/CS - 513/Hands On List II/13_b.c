#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<string.h>
#include<signal.h>
int main(int argc,char *argv[])
{

    int k=kill(atoi(argv[1]),17);
    printf("%d",k);
    perror("");
    return 0;
}
