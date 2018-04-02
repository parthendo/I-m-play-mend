/*Recursive method for checking whether a string is pallindrome or not*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000

int isPallindrome(char* str,int st,int ed){

	if(st<=ed){

		if(str[st]!=str[ed])
			return 0;
		return isPallindrome(str,st+1,ed-1);
		return 1;
	}
}

int main(){

	char str[MAX];
	scanf("%s",str);
	int l = strlen(str);
	int value = isPallindrome(str,0,l-1);
	if(value)
		printf("%s is a pallindrome\n",str);
	else
		printf("%s is not a pallindrome\n",str);
	return 0;
}
