/*
 * Solution to take input from STDIN and write on STDOUT using system calls
 * Author: MT2019074
 */
#include <unistd.h>

int main(){

	char buffer[1000];

	//fd = 0 is STDIN
	int x = read(0,buffer,100);
	//fd = 1 is STDOUT
	write(1,buffer,x);
	return 0;
}
