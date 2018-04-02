#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX 100
int main(){

	int arr[MAX],i,n,id,sumEven=0,sumOdd=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	id = (int)fork();
	if(id == 0){
		
		for(i=0;i<n;i++){
		
			if(arr[i]%2!=0)
				sumOdd+=arr[i];
		}
		printf("Sum of odd elements is : %d\n",sumOdd);
	}
	else{
		
		for(i=0;i<n;i++){

			if(arr[i]%2 == 0)
				sumEven+=arr[i];
		}
		printf("Sum of even elements is : %d\n",sumEven);
	}
	return 0;
}

