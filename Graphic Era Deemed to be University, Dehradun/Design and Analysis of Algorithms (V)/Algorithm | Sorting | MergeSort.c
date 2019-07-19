/*
 * Problem Statement: Merge Sort
 * TC = O(nlogn)
 * SC = O(n)
 * Not inplace or stable
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

void merge(int arr[],int l,int m,int r){

	int i,j,k;
	int N1 = m-l+1;
	int N2 = r-m;
	int A[N1+5],B[N2+5];
	for(i=0;i<N1;i++)
		A[i] = arr[l+i];
	for(i=0;i<N2;i++)
		B[i] = arr[m+1+i];
	i = 0,j = 0,k = l;
	while(i<N1 && j<N2){
		
		if(A[i] >= B[j])
			arr[k++] = B[j++];
		else
			arr[k++] = A[i++];
	}
	while(i<N1){
		arr[k++] = A[i++];
	}
	while(j<N2){
		arr[k++] = B[j++];
	}
}

void merge_sort(int arr[],int l,int h){
	
	if(l<h){
		
		int m = (h+l)/2;
		merge_sort(arr,l,m);
		merge_sort(arr,m+1,h);
		merge(arr,l,m,h);
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
	
	int n=5,i;
	int arr[MAX]={1,5,3,2,4};
	printf("Enter the size of array\n");
	scanf("%d",&n);
	printf("Enter the elements into array\n");
	for(i=0;i<n;i++){
	
		scanf("%d",&arr[i]);
	}
	merge_sort(arr,0,n-1);
	print(arr,n);
	return 0;
}

