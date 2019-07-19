/*
 * Problem statement: Given an integers, find if the bits are pallindromic or not
 * Sample I/P: 98304, 0, -1
 */
#include <iostream>
#include <cmath>
using namespace std;

bool pallindrome(int n){
	
	int l = sizeof(n)*8;
	cout << "bit representation -> ";
	for(int i=0;i<l;i++){
		if(n & (1<<(l-i-1)))
			cout << "1";
		else
			cout << "0";
	}
	cout << endl;
	for(int i=0;i<=l/2;i++){
	
		int front = n&(1<<(l-i-1));
		int back = n&(1<<i);
		if(!((front == 0 && back == 0) || (front!=0 && back!=0)))
			return false;
	}
	return true;
}

int main(){
	int n;
	cin >> n;
	if(pallindrome(n))
		cout << "Bits are pallindromic\n";
	else
		cout << "Bits are not pallindromic\n";
	return 0;
}
