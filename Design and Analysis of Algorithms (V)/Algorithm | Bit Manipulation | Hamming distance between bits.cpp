/*
 * Problem Statement: Count the number of bits to be flipped to make A from B
 */ 

#include <iostream>
using namespace std;

int hamming_distance(int A,int B){
	
	int a,b;
	int count = 0;
	int l = sizeof(int)*8;
	for(int i=0;i<l;i++){
		
		a = (A&(1<<i));
		b = (B&(1<<i));
		if((a!=0 && b==0) || (a==0 && b!=0))
			count++;
	}
	return count;
}

int main(){
	
	int A,B;
	cin >> A >> B;
	cout << hamming_distance(A,B)<<endl;
	return 0;
}
