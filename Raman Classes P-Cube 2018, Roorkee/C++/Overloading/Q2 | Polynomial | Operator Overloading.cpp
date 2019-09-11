#include <iostream>
#include <vector>
#include <utility>
#include <cstdarg>
#include "polynomial.h"
using namespace std;

polynomial :: polynomial(){
	
}
polynomial :: polynomial(int arg, ...){

		arg*=2;
		va_list array;
		va_start(array,arg);
		for(int i=1;i<=arg;i++){
			int power = va_arg(array,int);
			int coef = va_arg(array,int);
			eqn.insert({power,coef});
		} 
		va_end(array);
}
polynomial polynomial :: operator+(polynomial &obj){
	polynomial temp;
	set<pair<int,int> >::iterator it1,it2;
	it1 = eqn.begin();
	it2 = obj.eqn.begin();
	while(it1!=eqn.end() && it2!=obj.eqn.end()){
		if((*it1).first == (*it2).first){
			temp.set((*it1).first,(*it1).second+(*it2).second);
		}
		else if((*it1).first > (*it2).first){
			temp.set((*it1).first,(*it1).second);
		}
		else if((*it1).first < (*it2).first){
			temp.set((*it2).first,(*it2).second);
		}
	}
	return temp;
}
polynomial polynomial :: operator-(polynomial &obj){
	polynomial temp;
	set<pair<int,int> >::iterator it1,it2;
	it1 = eqn.begin();
	it2 = obj.eqn.begin();
	while(it1!=eqn.end() && it2!=obj.eqn.end()){
		if((*it1).first == (*it2).first){
			temp.set((*it1).first,(*it1).second-(*it2).second);
		}
		else if((*it1).first > (*it2).first){
			temp.set((*it1).first,(*it1).second);
		}
		else if((*it1).first < (*it2).first){
			temp.set((*it2).first,(*it2).second);
		}
	}
	return temp;
}
/*polynomial :: operator*(polynomial &obj){
	polynomial temp;
	set<pair<int,int> >::iterator it1,it2;
	for(it1 = eqn.begin();it1!=eqn.end();it++){
		for(it2 = obj.eqn.begin();it2!=obj.eqn.end();it2++){
			
		}
	}
	
}*/
void polynomial :: operator+=(polynomial &obj){
	this = this + obj;
}
void polynomial :: operator-=(polynomial &obj){
	this = this - obj;
}
ostream polynomial :: &operator<<(ostream ouput, polynomial &obj){
	
}
