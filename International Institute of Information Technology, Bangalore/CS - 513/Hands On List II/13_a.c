#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void intHandler(int signum) {
       printf("sorry,will not terminate the process");
   }

int main() {
   struct sigaction act;
   act.sa_handler = intHandler;
   sigaction(SIGSTOP, &act, NULL);
   for(;;);


}
