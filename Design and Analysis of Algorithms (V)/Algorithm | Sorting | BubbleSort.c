/*
 * Problem statement: Bubble sort
 * TC = O(n^2) 
 * SC = O(1)
 * bubble_sort(array,size,"INC"/"DSC")
 * Remarks: Inplace, stable
 */
#include <stdio.h>
#define MAX 100

void interchange(int* a,int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

void bubble_sort(int arr[],int n,const char *str){
	
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(str == "ASC" && arr[j]>arr[j+1]){
				interchange(&arr[j],&arr[j+1]);
			}
			else if(str == "DSC" && arr[j]<arr[j+1]){
				interchange(&arr[j],&arr[j+1]);
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
		bubble_sort(arr,n,"ASC");
	else if(mode == 2)
		bubble_sort(arr,n,"DSC");
	print(arr,n);
	return 0;
}


