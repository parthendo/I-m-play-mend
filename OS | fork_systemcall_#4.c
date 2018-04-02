#include <stdio.h>
#include <sys/types.h>
int main(){

	int ID;
	ID = fork();
	if(ID == 0){
		
		printf("Child process ID = %d Parent process ID = %d\n",getpid(),getppid());
		printf("hello\n");
	}
	else{
		
		printf("Child process ID = %d Parent process ID = %d\n",getpid(),getppid());
		printf("world\n");
	}
	return 0;
}
