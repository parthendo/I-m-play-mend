/*
 * Quick Sort
 * TC = WC: O(n^2) AC: O(nlogn)
 * SC = O(1)
 * Inplace but not stable
 */
#include <stdio.h>
#define MAX 10000

int partition(int arr[],int l,int h, const char *mode){
	int pivot = arr[h];
	int j,i = l-1,t;
	for(j = l;j<h;j++){

		if((arr[j]>=pivot && mode == "DSC") || (arr[j]<=pivot && mode == "ASC")){
			
			i++;
			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}
	t = arr[i+1];
	arr[i+1] = pivot;
	arr[h] = t;
	return i+1;
}

void quick_sort(int arr[],int l,int r,const char* mode){
	if(l<r){
		int m = partition(arr,l,r,mode);
		quick_sort(arr,l,m-1,mode);
		quick_sort(arr,m+1,r,mode);
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
		quick_sort(arr,0,n-1,"ASC");
	else
		quick_sort(arr,0,n-1,"DSC");
	print(arr,n);	
	return 0;
}
