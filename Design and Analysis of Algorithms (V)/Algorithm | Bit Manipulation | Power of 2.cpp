/*
 * Problem Statement: Check if the given integer is in power of 2 or not
 */ 
#include <iostream>
#include <algorithm>
using namespace std;

bool method1(int n){

	int temp = __builtin_popcount(n);
	if(temp == 1)
		return true;
	return false;
}

bool method2(int n){
	
	int count = 0,l = sizeof(int)*8;
	for(int i=0;i<l;i++){
		if(n&(1<<i))
			count++;
	}
	if(count == 1)
		return true;
	return false;
}

bool method3(int n){
	return (n && !(n&(n-1)));
}

int main(){
	int n;
	cin >> n;
	if(method1(n) && method2(n) && method3(n))
		cout << "Power of 2" << endl;
	else
		cout << "negative" << endl;
	return 0;
}
