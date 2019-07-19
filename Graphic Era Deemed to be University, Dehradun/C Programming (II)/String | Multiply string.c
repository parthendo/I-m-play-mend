/*
 * Problem Statement: Concatenate string n number of times
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000

char* repeat(char *s,int n){
	 
	 int i,j,l = strlen(s);
	 //char str[MAX];
	 char* str = (char*) malloc(sizeof(char)*(l+5));
	 for(i=0;i<n;i++){
		 for(j=0;j<l;j++){
			 str[i*l+j] = s[j];
		 }
	 }
	 str[(n-1)*i+l+1] = '\0';
	 s = str;
	 //printf("%s\n",s);
	 return s;
}

int main(){

	int n;
	char str[MAX],*p;
	p = str;
	scanf("%s %n",str,&n);
	/* This function clears the buffer, 
	 * generally buffer is cleared using
	 * a newline character.
	 */
	setbuf(stdout, NULL);
	printf("%s\n",repeat(p,n));
	return 0;
}
