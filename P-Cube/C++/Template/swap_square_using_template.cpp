/*
 * Problem: Implement swap and square function using templates
 */
#include <iostream>
using namespace std;

template <class T>
void Swap(T &a, T &b){
  T t=a;a=b,b=t;
}

template <class T>
T square(T a){
  return a*a;
}

int main(){

  int a = 5;
  int b = 7;
  cout << a <<" "<< b << endl;
  Swap(a,b);
  cout << a <<" "<< b << endl;
  b = square(a);
  cout << a <<" "<< b << endl;
  return 0;
}
