/*
 * Problem Statement: Given a positive number N, output where it is possible to fit N queens 
 * 					  such that no queen can kill other. If there is a way, print it.
 * Sample Input:
 * N = 4
 * Sample Output:
 * 0010
 * 1000
 * 0001
 * 0100
 */
#include <iostream>
#define MAX 100
using namespace std;

bool isSafe(int arr[][MAX],int r,int c,int n){
	for(int i=r;i>=0;i--)
		if(arr[i][c])
			return false;
	for(int i=c;i>=0;i--)
		if(arr[r][i])
			return false;
	for(int i=r,j=c;i>=0 && j>=0;i--,j--){
		if(arr[i][j])
			return false;
	}
	for(int i=r,j=c;i<n && j>=0;i++,j--){
		if(arr[i][j])
			return false;
	}
	return true;
}

int NQ(int arr[][MAX],int n,int col){
	
	if(col>=n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cout << arr[i][j];
			cout << endl;
		}
		cout << endl;
		return 1;
	}
	for(int i=0;i<n;i++){
		if(isSafe(arr,i,col,n)){
			arr[i][col] = 1;
			if(!NQ(arr,n,col+1))
				arr[i][col] = 0;
			else
				return 1;
		}
	}
	return 0;
}

int main(){
	
	int arr[MAX][MAX];
	int n;
	cin >> n;
	if(!NQ(arr,n,0))
		cout << "No configuration is possible\n";
	return 0;
}
