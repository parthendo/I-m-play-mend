#include <iostream>
using namespace std;

class Implement{

private:
  int pos;
  int size;
  int *space;
public:
  Implement(int s){
    pos = -1;
    size = s;
    space = (int*)malloc(sizeof(int)*size);
  }
  void add(int value){

    space[++pos] = value;
  }
  Implement(Implement &obj){

      Implement t;
      t.pos =
  }
  Implement operator =(Implement &obj){

  }
};
