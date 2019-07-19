#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

void selection_sort(int arr[],int n, int mode){

	int i,j,mx,pos;
	for(i=0;i<n-1;i++){

		mx = arr[i];
		pos = i;
		for(j=i+1;j<n;j++){
		
			if(mode == 2){
			
				if(arr[j] > mx){
					mx = arr[j];
					pos = j;
				}
			}
			else{
			
				if(arr[j] < mx){
					mx = arr[j];
					pos = j;
				}
			}
		}
		arr[pos] = arr[i];
		arr[i] = mx;
	}
}
void print(int arr[],int n){

	int i;
	printf("The sorted array is -> ");
	for(i=0;i<n;i++)
		printf(" %d",arr[i]);
	printf("\n");
}

int main(){

	int n,i,mode;
	int arr[MAX];
	printf("Enter the size of array\n");
	scanf("%d",&n);
	printf("Enter the elements into array\n");
	for(int i=0;i<n;i++){
	
		scanf("%d",&arr[i]);
	}
	printf("Enter\n1 for Ascendig \n2 for Descending\n");
	scanf("%d",&mode);
	selection_sort(arr,n,mode);
	print(arr,n);
	return 0;
}