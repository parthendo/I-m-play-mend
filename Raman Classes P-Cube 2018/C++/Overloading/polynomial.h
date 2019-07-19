#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include<ostream>
#include<utility>
#include<set>
#include<cstdarg>
using namespace std;

class polynomial{

private:
	set<pair<int,int>> eqn;
public:
	polynomial();
	polynomial(int args, ...);
	polynomial operator+(polynomial &obj);
	polynomial operator-(polynomial &obj);
//	polynomial operator*(polynomial &obj);
//	polynomial operator=(polynomial &obj);
	void operator+=(polynomial &obj);
	void operator-=(polynomial &obj);
//	polynomial operator*=(polynomial &obj);
	ostream &operator<<(ostream output,polynomial &obj);
	istream &operator>>(istream output,polynomial &obj);
	int get(int);
	void set(int,int); 
}; 

#endif
