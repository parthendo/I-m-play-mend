/*Understanding the concept of output buffer and fork system call
  Expected output:HellohowareyouHellohowareyouHellohowareyouHellohowareyouHellohowareyouHellohowareyouHellohowareyouHellohowareyou*/

#include <stdio.h>
#include <sys/types.h>

int main(){

	printf("Hello");
	fork();
	printf("how");
	fork();
	printf("are");
	fork();
	printf("you");
	return 0;
}
