#include <stdio.h>
#define MAX 100
int main(){

	int arr[MAX],i,n,ID,sumEven=0,sumOdd=0;
	scanf(“%d”,&n);
	for(i=0;i<n;i++)
		scanf(“%d”,&arr[i]);
	id = fork();
	if(id == 0){
		
		for(i=0;i<n;i+=2){
		
			sumEven+=arr[i];
		}
		printf(“Sum of even positioned elements is : %d\n”,sumEven);
	}
	else{
		
		for(i=1;i<n;i+=2){

			sumOdd+=arr[i];
		}
		printf(“Sum of odd positioned elements is : %d\n”,sumOdd);
	}
	return 0;
}
