#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(){

	int PID = fork();
	if(PID>0){
		
		sleep(50);
	}
	else{
		
		exit(0);
	}
	return 0;
}

/*How to execute:

parthendo@markus:~/Desktop/Lab/OS lab$ gcc OSlab3_2.c 
parthendo@markus:~/Desktop/Lab/OS lab$ ./a.out &
[2] 2738
parthendo@markus:~/Desktop/Lab/OS lab$ ps aux
USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND

root          2520  0.0  0.0      0     0 ?        S    20:33   0:00 [kworker/0:1]
root          2561  0.0  0.0      0     0 ?        S    20:34   0:00 [kworker/3:1]
parthendo+  2571  0.9  0.4 619392 34596 ?        Sl   20:34   0:04 geany
root          2581  0.0  0.0      0     0 ?        S    20:34   0:00 [kworker/u8:0]
root          2584  0.0  0.0      0     0 ?        S    20:34   0:00 [kworker/2:3]
root          2615  0.0  0.0      0     0 ?        S    20:34   0:00 [kworker/1:0]
parthendo+  2648  0.2  0.4 659196 36536 ?        Sl   20:36   0:00 /usr/lib/gnome-
parthendo+  2655  0.0  0.0  22768  5564 pts/4    Ss   20:36   0:00 bash
root          2711  0.0  0.0      0     0 ?        S    20:39   0:00 [kworker/3:2]
root          2714  0.0  0.0      0     0 ?        S    20:39   0:00 [kworker/1:1]
root          2715  0.0  0.0      0     0 ?        S    20:39   0:00 [kworker/2:1]
parthendo+  2730  0.0  0.0   4224   792 pts/4    T    20:41   0:00 ./a.out
parthendo+  2731  0.0  0.0      0     0 pts/4    Z    20:41   0:00 [a.out] <defunc
parthendo+  2738  0.0  0.0   4224   664 pts/4    S    20:41   0:00 ./a.out
parthendo+  2739  0.0  0.0      0     0 pts/4    Z    20:41   0:00 [a.out] <defunc
parthendo+  2740  0.0  0.0  37364  3376 pts/4    R+   20:41   0:00 ps aux*/
