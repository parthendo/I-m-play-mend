/*
 * Problem statement: Print all pallindromes greater than 2
 */

#include <stdio.h>
#include <string.h>
#define MAX 10000

int pallindrome(char *s){
	
	int i,l = strlen(s);
	for(i=0;i<l/2;i++)
		if(s[i]!=s[l-i-1])
			return 0;
	return 1;
}
void print_pallindrome(char *str){
	int i,l = strlen(str);
	if(pallindrome(str) && l>2){
		for(i=0;i<l;i++)
			printf("%c",str[i]);
		printf("\n");
	}
}

void compute(char *s){
	
	int i,j,k,l = strlen(s);
	for(i=0;i<l;i++){
		for(j=i;j<l;j++){
			char str[MAX];
			memset(str,'\0',sizeof(str));
			int p = 0;
			for(k=i;k<=j;k++)
				str[p++] = s[k];
			print_pallindrome(str);
		}
	}
}

int main(){
		
	char str[MAX];
	scanf("%s",str);
	compute(str);
	return 0;
}
