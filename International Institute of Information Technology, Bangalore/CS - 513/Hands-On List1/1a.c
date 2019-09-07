/*
 * C program to create a softlink of the file given as input
 * Author: MT2019074
 */
#include <unistd.h>
#include <stdio.h>

int main(int argc,char* argv[]){
	if(argc != 2){
		printf("Enter only the file name or the path of the file\n"); 
	}
	else{
		int sflnk = symlink(argv[1],"1_mySoftLink");
		perror(" ");
		printf("%d\n",sflnk);
	}
	return 0;
}
