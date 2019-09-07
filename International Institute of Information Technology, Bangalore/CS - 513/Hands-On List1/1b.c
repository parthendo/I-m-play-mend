/*
 * C program to create a hardlink of the file given as input
 * Author: MT2019074
 */
#include <unistd.h>
#include <stdio.h>

int main(int argc,char* argv[]){
	if(argc != 2){
		printf("Enter only the file name or the path of the file\n"); 
	}
	else{
		int lnk = link(argv[1],"1_myHardLink");
		perror(" ");
		printf("%d\n",lnk);
	}
	return 0;
}

