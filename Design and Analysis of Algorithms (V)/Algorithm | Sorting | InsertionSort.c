/*
 * Insertion sort
 * SC= O(1)
 * TC= BC: O(n) WC: O(n^2)
 * Not inplace but stable
 */

#include <stdio.h>
#define MAX 10000

void insertion_sort(int arr[],int n,const char *str){
	
	int t,p;
	for(int i=1;i<n;i++){
		
		p = i;
		if(str == "ASC"){
			while(p>=1 && arr[p]<arr[p-1]){	
				t = arr[p];
				arr[p] = arr[p-1];
				arr[p-1] = t;
				p--;
			}
		}
		else if(str == "DSC"){
			while(p>=1 && arr[p]>arr[p-1]){	
				t = arr[p];
				arr[p] = arr[p-1];
				arr[p-1] = t;
				p--;
			}
		}
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
	if(mode == 1)
		insertion_sort(arr,n,"ASC");
	else
		insertion_sort(arr,n,"DSC");
	print(arr,n);
	return 0;
}
