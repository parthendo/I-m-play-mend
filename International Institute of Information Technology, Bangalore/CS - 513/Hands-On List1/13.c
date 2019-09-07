/*
 * 13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not (check in $man 2 select).
 * Author: MT2019074
 */
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
    fd_set rfds;
    struct timeval timeSet;
    int select_return;
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    timeSet.tv_sec = 10;
    timeSet.tv_usec = 0;
    select_return = select(1, &rfds, NULL, NULL, &timeSet);
    if(select_return){
        printf("Data is available now\n");
    }
    else{
        printf("No data was available within 10 seconds\n");
    }
    return 0;
}
