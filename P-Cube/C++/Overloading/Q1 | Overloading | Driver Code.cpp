#include <iostream>
#include <algorithm>
#include <vector>
#include "fraction.h"
using namespace std;

int main(){
	fraction obj(1,5);
	fraction obj1(1,6);
	cout<<(obj>obj1)<<endl;
	fraction obj2(1,4);
	fraction obj3(1,2);
	obj2.swap(obj3);
	cout<<obj2<<" "<<obj3;
	fraction obj4(1,3);
	vector<fraction> obja;
	obja.push_back(obj);
	obja.push_back(obj1);
	obja.push_back(obj2);
	obja.push_back(obj3);
	obja.push_back(obj4);
	obj.sort(obja);
	for(int i=0;i<5;i++)
		cout<<obja[i]; 
	return 0;
}
