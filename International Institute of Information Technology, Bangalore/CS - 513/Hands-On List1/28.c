#include<stdio.h>
#include<sched.h>

int main(int argc, char const *argv[]){
    printf("Maximum real time priority: %d\n", sched_get_priority_max(SCHED_FIFO));
    printf("Minimum real time priority: %d\n", sched_get_priority_min(SCHED_FIFO));
    return 0;
}
