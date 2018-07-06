#include <bits/stdc++.h>
#include "mystack.h"
using namespace std;

/*
 * This code features multiple concepts like 
 * 1. Variable arguments to the function
 * 2. Overloading stream objects
 * 3. Multiple overloading + operator
 * 4. Template with structure and class
 */
mystack :: mystack(){
	elements = 0;
	stackptr = NULL; 
}
//Variable arguments to the function
mystack :: mystack(int argc, ...){
	stackptr = NULL;
	va_list array;
	va_start(array,argc);
	for(int i=1;i<=argc;i++){
		struct nd<int> *temp = (struct nd<int>*)malloc(sizeof(struct nd<int>));
		elements++;
		int v = va_arg(array,int);
		temp->val = v;
		temp->next = NULL;
		if(stackptr == NULL)
			stackptr = temp;
		else{
			temp->next = stackptr;
			stackptr = temp;
		}
	}
	va_end(array);
}
ostream &operator<<(ostream &output,mystack &obj){
	
	struct nd<int> *temp = obj.stackptr;
	while(temp!=NULL){
		output<<temp->val<<" ";
		temp = temp->next;
	}
	return output;
}
istream &operator>>(istream &input,mystack &obj){
	
	while(1){
		string inp;
		input>>inp;
		if(inp == "-0")
			break;
		else{
			struct nd<int> *temp = (struct nd<int>*)malloc(sizeof(struct nd<int>));
			const char* t = inp.c_str();
			int value = atoi(t);
			temp->val = value;
			obj.elements++;
			temp->next = NULL;
			if(obj.stackptr == NULL)
				obj.stackptr = temp;
			else{
				temp->next = obj.stackptr;
				obj.stackptr = temp;
			}
		}
	}
	return input;
}
void mystack::push(int n){
	
	elements++;
	struct nd<int> *temp = (struct nd<int>*)malloc(sizeof(struct nd<int>));
	temp->val = n;
	temp->next = NULL;
	if(stackptr == NULL)
		stackptr = temp;
	else{
		temp->next = stackptr;
		stackptr = temp;
	}
}
void mystack::pop(){
	struct nd<int> *temp = stackptr;
	stackptr = stackptr->next;
	elements--;
	free(temp);
}
int mystack::top(){
	return stackptr->val;
}
bool mystack::isEmpty(){
	if(elements == 0)
		return true;
	return false;
}
int mystack::size(){
	return elements;
}
void mystack::operator+(int n){
	this->push(n);
}
mystack mystack::operator+(mystack &obj){
	mystack temp,temp1;
	temp=(*this);
	temp1=obj;
	temp1.reverse();
	int l = obj.size();
	for(int i=0;i<l;i++){
		temp.push(temp1.top());
		temp1.pop();
	}
	return temp;
}
void mystack::reverse(){
	vector<int> arr;
	int l = this->size();
	for(int i=1;i<=l;i++){
		arr.push_back(this->top());
		this->pop();
	}
	for(int i = 0;i<l;i++){
		this->push(arr[i]);
	}
}
