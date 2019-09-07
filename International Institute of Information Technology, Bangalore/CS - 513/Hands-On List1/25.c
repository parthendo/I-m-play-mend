/*
 * Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call)
 * Author: MT2019074
*/
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int parent_pid = getpid();
    int wstatus;
    pid_t child_pid1, child_pid2, child_pid3;
    printf("Parent Process PID %d\n", parent_pid);
    child_pid1 = fork();
    if(child_pid1 == 0){
        sleep(5);
    }
    else{
        child_pid2 = fork();
        if(child_pid2 == 0){
            sleep(10);
        }
        else{
            child_pid3 = fork();
            if(child_pid3 == 0){
                sleep(15);
            }
        }

    }
    if(parent_pid == getpid()){
        printf("Child PIDs are\n");
        printf("Child 1 PID: %d\n", child_pid1);
        printf("Child 2 PID: %d\n", child_pid2);
        printf("Child 3 PID: %d\n", child_pid3);
        printf("Waiting for Child 2 PID %d\n", child_pid2);
        pid_t return_wait = waitpid(child_pid2, &wstatus, 0);
        if(return_wait == child_pid2){
            printf("Parent successfully waited for Child 2, Return value is %d\n", return_wait);
        }
        else{
            perror("Error: ");
        }
    }
    return 0;
}
