/*
 * Problem Statement: Find the power of two just bigger than the given number
 */ 

#include <iostream>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	int count = 0;
	while(n>0){
		
		n = n>>1;
		count++;
	}
	n = 1;
	for(int i=0;i<count;i++)
		n = n << 1;
	cout << n << endl;
	return 0;
}
