/*
 * Problem Statement: Implement atoi function
 * Sample Input: 9 7068
 * Sample Output: 9
 */  
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000

long int Atoi(char *str){
	
	int i,l = strlen(str);
	long int num = 0;
	for(i=0;i<l;i++){
		
		if(str[i]>='0' && str[i]<='9')
			num = (num*10)+(str[i]-'0');
		else
			break;
	}
	return num;
}

int main(){
	
	char str[MAX];
	scanf("%s",str);
	printf("%ld\n",Atoi(str));
	return 0;
}
