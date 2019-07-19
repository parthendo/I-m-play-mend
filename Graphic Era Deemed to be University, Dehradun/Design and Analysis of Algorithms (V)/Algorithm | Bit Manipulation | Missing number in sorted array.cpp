/*
 * Problem Statement: Given n-1 integers from [1,n], find the missing number
 */ 

#include <iostream>
using namespace std;

int main(){
	
	int n,temp,sum = 1;
	cin >> n;
	for(int i=0;i<n-1;i++){
		cin >> temp;
		sum^=temp;
	}
	cout << sum << endl;
	return 0;
}
