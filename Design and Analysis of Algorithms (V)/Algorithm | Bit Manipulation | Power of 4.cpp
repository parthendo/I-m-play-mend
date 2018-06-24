/*
 * Problem statement: Check is a given number is power of 4
 */
#include <iostream>
using namespace std;

bool check_power(int n){
	
	int count=0,pos;
	int l = sizeof(int)*8;
	for(int i=0;i<l;i++){
	
		if(n&(1<<i)){
			
			count++;
			pos = i;
		}
	}
	if(count == 1 && pos%2 == 0)
		return true;
	return false;
}

int main(){
	
	int n;
	cin >> n;
	if(check_power(n))
		cout << "Number is divisible by 4\n";
	else
		cout << "Number is not divisible by 4\n";
	return 0;
}
