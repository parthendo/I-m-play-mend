#include <unistd.h>
#include </usr/include/linux/fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ulimit.h>
#define _GNU_SOURCE

int main(){

	write(1,"Maximum open file: ",sizeof("Maximum open file: "));
	system("ulimit -n");
	write(1,"Pipe size: ",sizeof("Pipe size: "));
	system("ulimit -p");
	return 0;
}