#include<iostream>
#include"mystack.h"
using namespace std;

int main(){
	
	mystack obj;
	mystack obj1(3,4,5,6);
	mystack obj2(6,1,2,3,4,5,6);
	cin>>obj;
	cout<<"Obj --> ";
	cout<<obj<<endl;
	obj.push(999);
	obj+998;
	cout<<"Obj1--> ";
	cout<<obj1<<endl;
	cout<<(obj.top())<<endl;
	obj.pop();
	cout<<"Obj --> ";
	cout<<obj<<endl;
	cout<<(obj.size())<<endl;
	obj2 = obj+obj1;
	cout<<obj2<<endl;
	cout<<obj<<endl;
	return 0;
}
