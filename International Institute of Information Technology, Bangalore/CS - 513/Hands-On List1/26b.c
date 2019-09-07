/*
 * 26. Write a program to execute an executable program.
 * a. use some executable program
 * b. pass some input to an executable program. (for example execute an executable of $./a.out name)
 * Author: MT2019074
 */

#include<stdio.h>
#include<unistd.h>

extern char **environ;

int main(int argc, char const *argv[]){    
    int execl_ = execl("26D", "26D", "XYZ", (char *)NULL);
    printf("%d\n", execl_);
    return 0;
}
