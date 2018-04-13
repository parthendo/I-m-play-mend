/*Performing nCr using dynamic programming paradigm*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int main(){

	int C[MAX][MAX];
	int n,r,i,j;
	printf("Code to evaluate nCr\nEnter values of n and r\n");
	scanf("%d%d",&n,&r);
	for(i=0;i<MAX;i++){
		C[0][i] = 0;
		C[i][0] = 1;
	}
	for(i=1;i<MAX;i++)
		for(j=1;j<MAX;j++)
			C[i][j] = C[i-1][j-1] + C[i-1][j];
	printf("Value of %dC%d is %d\n",n,r,C[n][r]);
	return 0;
}