/*Greedy 0/1 Knapsack may or may not give optimum solution to the problem but
the dynamic programming version ensures it.
Capacity = 10
Weight 2 3 4 6
Cost   3 4 8 8
*/

#include <stdio.h>
#define MAX 1000
#define max(a,b) (a>=b)?a:b

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
	for(i=0;i<=capacity;i++){

		for(j=0;j<=n;j++){

			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else if(i>=weight[j])
				temp = dp[i-weight[j]][j-1]+cost[j];
			else
				temp = 0;
			dp[i][j] = max(temp,dp[i][j-1]);
		}
	}
	printf("Maximum benefit is %d\n",dp[capacity][n]);

	return 0;
}
