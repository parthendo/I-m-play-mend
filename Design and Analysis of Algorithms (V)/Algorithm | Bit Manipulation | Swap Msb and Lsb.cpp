/*
 * Problem statement: Given an integers, swap its msb and lsb bits
 * Sample I/P: 
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

void print_bits(int n){
	
	int l = sizeof(n)*8;
	cout << "bit representation -> ";
	for(int i=0;i<l;i++){
		if(n & (1<<(l-i-1)))
			cout << "1";
		else
			cout << "0";
	}
	cout << endl;d
}

int main(){
	
	bool msbset = false,lsbset = false;
	int n,l;
	cin >> n;
	print_bits(n);
	l = sizeof(int)*8;
	if(n%2 != 0)
		lsbset = true;
	if(n<0)
		msbset = true;
	l--;
	if(lsbset!=msbset){
		
		if(msbset){
			
			n = n ^ (0<<l);
			n = n | (1<<0);
		}
		else{
			
			n = n | (1 << l);
			n = n ^ (1 << 0);
		}
	}
	print_bits(n);
	cout << n << endl;
	return 0;
}
