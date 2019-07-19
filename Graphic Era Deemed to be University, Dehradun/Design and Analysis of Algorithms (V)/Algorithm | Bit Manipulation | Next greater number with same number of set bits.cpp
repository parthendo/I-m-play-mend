/*
 * Problem statement: Find the number bigger than given number having equal
 * number of bits.
 */ 
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	
	int n,l,temp,msb = 0,setcount;
	l = sizeof(int)*8;
	//cin >> n;
	n = 13;
	temp =  n;
	//setcount = __builtin_popcount(n);
	while(temp>0){
		msb++;
		temp=temp>>1;
	}
	temp = pow(2,msb);
	temp--;
	cout << msb << " "<<temp<<endl;
	for(int i=0;i<l;i++){
		
		for(int j=i-1;j>=0;j--){
			
		}
	}
	return 0;
}
