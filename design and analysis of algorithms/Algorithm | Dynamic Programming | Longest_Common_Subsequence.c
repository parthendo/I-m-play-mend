/*This code takes in two strings as an input and does character matching
to find LCS using dynamic programming paradigm
This code can also be used for an example of gene matching
Sample input
Parent String: AGTCA
Child String: ACA*/
#include <stdio.h>
#include <string.h>
#define MAX 10005

//Declared globally, thus array is completely initialized by 0
int dp[MAX][MAX];

int main(){

	char parent[MAX],child[MAX];
	printf("Enter parent string\n");
	scanf("%s",parent);
	printf("Enter child string\n");
	scanf("%s",child);
	int parent_len = strlen(parent);
	int child_len = strlen(child);
	int i,j;
	for(i=0;i<parent_len;i++){

		for(j=0;j<child_len;j++){

			if(parent[i] == child[j])
				dp[i+1][j+1] = dp[i][j]+1;
			else
				dp[i+1][j+1] = (dp[i][j+1]>=dp[i+1][j])? dp[i][j+1]:dp[i+1][j];
		}
	}
	printf("The longest common subsequence is %d\n",dp[parent_len][child_len]);
	return 0;
}
