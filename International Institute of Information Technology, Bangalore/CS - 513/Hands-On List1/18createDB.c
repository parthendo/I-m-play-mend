#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
	
	int fd;
	fd = open("18db",O_CREAT|O_RDWR,0744);
	write(fd,"abcdefgh\n",sizeof("abcdefgh")+1);
	write(fd,"ijklmnop\n",sizeof("ijklmnop")+1);
	write(fd,"prrstuvw",sizeof("prrstuvw"));
	close(fd);
	return 0;
}
