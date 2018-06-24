#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	int n,l;
	cin >> n;
	int ans = 0;
	l = sizeof(int)*8;
	for(int i=0;i<l;i++){
		
		if(n & (1<<(l-i-1))){
			cout << "1";
			ans = ans | (1 << i);
		}
		else
			cout << "0";
	}
	cout << endl;
	cout << ans << endl;
	for(int i=0;i<l;i++){
		if(ans & (1<<(l-i-1)))
			cout << "1";
		else
			cout << "0";
	}
	cout << endl;
	return 0;
}
