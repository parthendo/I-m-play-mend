/*Greedy 0/1 Knapsack may or may not give optimum solution to the problem but
the dynamic programming version ensures it.*/

#include <stdio.h>
#define MAX 1000
#define max(a,b) (a==b)?a:b

int dp[MAX][MAX];

int main(){

	int i,j,n,capacity, weight[MAX],cost[MAX],temp;
	printf("Enter the capacity of sack ");
	scanf("%d",&capacity);
	printf("Enter the number of items ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
	
		printf("Enter weight and cost of item %d: ",i);
		scanf("%d %d",&weight[i],&cost[i]);
	}
	for(i=1;i<=n;i++){

		for(j=1;j<=capacity;j++){

			if(capacity>weight[j])
				temp = dp[i-weight[j]][j-1]+cost[j];
			else
				temp = 0;
			dp[i][j] = max(temp,dp[i][j-1]);
		}
	}
	for(i=0;i<10;i++){
		for(j=0;j<10;j++)
			printf("%d ",dp[i][j]);
		printf("\n");
	}
	printf("Maximum benefit is %d\n",dp[capacity][n]);

	return 0;
}
