#include <iostream>
using namespace std;

class test{

private:
  int a;
  int b;
public:
  test(){

  }
  test(int a,int b){
    this->a = a;
    this->b = b;
  }
  friend ostream &operator <<(ostream &Ct,test &obj){
    Ct << 2*obj.a << "\n";
  }
  test operator +(test &obj){
    test t;
    t.a = a + obj.a;
    t.b = b + obj.b;
    return t;
  }
  test operator -(){
    a*=-1;
    b*=-1;
  }
  test operator ++(){
    a++;
    b++;
  }
  test operator ++(int){
    a++;
    b++;
    return *this;
  }
};
int main(){
  test obj(3,4);
  test obj1(5,6);
  test obj3 = obj+obj1;
  cout<<obj;
  cout<<obj3;
  ++obj3;
  -obj3;
  cout<<"$"<<obj3;
  test obj4=obj3++;
  cout<<obj4;
  return 0;
}
