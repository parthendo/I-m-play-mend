#include <iostream>
#include <algorithm>
#include "fraction.h"
using namespace std;

ostream &operator<<(ostream &output,fraction &obj){
	if(obj.denominator == 1)
		output << obj.numerator << endl;
	else
		output << obj.numerator << "/" << obj.denominator << endl;  
	return output;
}
fraction :: fraction(){
	numerator = 0;
	denominator = 0;
}
fraction :: fraction(int a,int b){
	numerator = a;
	denominator = b;
}
int fraction::lcm(fraction &obj){
	int temp = __gcd(denominator,obj.denominator);
	int lcm = (denominator*obj.denominator)/temp;
	return lcm;
}
int fraction :: getNumerator(){
	return numerator;
}
int fraction :: getDenominator(){
	return denominator;
}
fraction fraction::operator+(fraction &obj){
	fraction t;
	int temp = this->lcm(obj);
	t.numerator = numerator*(temp/denominator) + obj.numerator*(temp/obj.denominator);
	t.denominator = temp;
	return t;
}
fraction fraction::operator-(fraction &obj){
	fraction t;
	int temp = this->lcm(obj);
	t.numerator = numerator*(temp/denominator) - obj.numerator*(temp/obj.denominator);
	t.denominator = temp;
	return t;
}
fraction fraction::operator*(fraction &obj){
	fraction t;
	t.numerator = numerator * obj.numerator;
	t.denominator = denominator * obj.denominator;
	if(t.numerator < 0 && t.denominator < 0){
		t.numerator*=-1;
		t.denominator*=-1;
	}
	int temp = __gcd(abs(t.numerator),abs(t.denominator));
	t.numerator/=temp;
	t.denominator/=temp;
	return t;
}
fraction fraction::operator/(fraction &obj){
	fraction t;
	t.numerator = numerator * obj.denominator;
	t.denominator = denominator * obj.numerator;
	if(t.numerator < 0 && t.denominator < 0){
		t.numerator*=-1;
		t.denominator*=-1;
	}
	int temp = __gcd(abs(t.numerator),abs(t.denominator));
	t.numerator/=temp;
	t.denominator/=temp;
	return t;
}
bool fraction::operator<(fraction &obj){
	int temp = __gcd(denominator,obj.denominator);
	int temp_numerator;
	int temp_numerator1;
	temp_numerator = numerator * (temp/denominator);
	temp_numerator1 = obj.numerator * (temp/obj.denominator);
	if(temp_numerator < temp_numerator1)
		return true;
	else
		return false;
}
bool fraction::operator==(fraction &obj){
	int temp = __gcd(denominator,obj.denominator);
	int temp_numerator = numerator * (temp/denominator);
	int temp_numerator1 = obj.numerator * (temp/obj.denominator);
	if(temp_numerator == temp_numerator1)
		return true;
	else
		return false;
}
bool fraction::operator>(fraction &obj){
	fraction t;
	t.numerator = numerator;
	t.denominator = denominator;
	if(t<obj)
		return false;
	return true;
}
bool fraction::operator>=(fraction &obj){
	fraction t;
	t.numerator = numerator;
	t.denominator = denominator;
	if(t>obj || t==obj)
		return true;
	return false;
}
bool fraction::operator<=(fraction &obj){
	fraction t;
	t.numerator = numerator;
	t.denominator = denominator;
	if(t<obj || t==obj)
		return true;
	return false;
}
bool fraction::operator!=(fraction &obj){
	fraction t;
	t.numerator = numerator;
	t.denominator = denominator;
	if(!(t==obj))
		return true;
	return false;
}
fraction fraction::operator++(){
	fraction t;
	t.numerator = numerator+denominator;
	numerator = numerator+denominator;
	t.denominator = denominator;
	return t;
}
fraction fraction::operator++(int){
	fraction t;
	t.numerator = numerator;
	numerator = numerator+denominator;
	t.denominator = denominator;
	return t;
}
fraction fraction::operator--(){
	fraction t;
	t.numerator = numerator-denominator;
	numerator = numerator-denominator;
	t.denominator = denominator;
	return t;
}
fraction fraction::operator--(int){
	fraction t;
	t.numerator = numerator;
	numerator = numerator-denominator;
	t.denominator = denominator;
	return t;
}
fraction fraction::operator-()const{
	fraction t;
	t.numerator = numerator*(-1);
	t.denominator = denominator;
	return t;
}
void fraction::swap(fraction &obj){
	
	int a = obj.numerator;
	int b = obj.denominator;
	obj.numerator = numerator;
	obj.denominator = denominator;
	numerator = a;
	denominator = b;
}
//Under construction
void fraction::sort(std::vector<fraction> obj){
	
	int n = obj.size();
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(obj[i]>obj[j]){
				//cout<<"*"<<obj[j]<<'\t'<<obj[j+1];
				obj[i].swap(obj[j]);
				//cout<<obj[j]<<'\t'<<obj[j+1];
			}
		}
	}
	for(int i=0;i<5;i++)
		cout<<obj[i]; 
}
