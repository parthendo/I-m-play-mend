#include <signal.h>
#include <stdlib.h>

#include<stdio.h>
 void intHandler(int signum) {
    printf("sorry,will not terminate the process");
}

int main() {
    struct sigaction act;
    act.sa_handler = intHandler;
    sigaction(SIGINT, &act, NULL);

  getchar();
}
