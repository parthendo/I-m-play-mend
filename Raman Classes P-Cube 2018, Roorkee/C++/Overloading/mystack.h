#ifndef MYSTACK_H
#define MYSTACK_H
#include <iostream>
using namespace std;
template<typename V>struct nd{

		V val;
		struct nd *next;
	};
class mystack{

private:
	int elements;
	struct nd<int> *stackptr;
public:
	mystack();
	mystack(int n_args, ...);
	friend ostream &operator<<(ostream &output,mystack &obj);
	friend istream &operator>>(istream &input,mystack &obj);
	void push(int n);
	void pop();
	int top();	
	bool isEmpty();
	int size();	
	void operator+(int n);
	mystack operator+(mystack &obj);
	void reverse();	
};

#endif
