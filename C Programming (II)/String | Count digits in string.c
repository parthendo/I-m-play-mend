/*
 * Problem Statement: Count the number of digits in a string
 */

#include <stdio.h>
#include <string.h>
#define MAX 1000

int main(){

	int l,count=0,i;
	char str[MAX];
	scanf("%s",str);
	l = strlen(str);
	for(i=0;i<l;i++)
		if(str[i]>='0' && str[i]<='9')
			count++;
	printf("Digits in %d\n",count);
	return 0;
}
