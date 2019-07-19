#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b

int euclid(int a, int b){

	if(b>1)
		return euclid(b,a%b);
	return b;
}

int main(){

	int p,q;
	printf("Enter the two numbers\n");
	scanf("%d%d",&p,&q);
	if(euclid(max(p,q),min(p,q)) == 1)
		printf("%d & %d are co-prime numbers\n",p,q);
	else
		printf("%d & %d are not co-prime numbers\n",p,q);
	return 0;
}