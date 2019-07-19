#include <iostream>
#include <vector>
using namespace std;

class Implement{
public:
  vector<int> arr;
  Implement();
  Implement(vector<int>);
  void delete_element();
};

Implement::Implement(){

  cout << "This is a default constructor\n";
}
Implement::Implement(vector<int> temp_arr){

  cout << "This is a parameterized constructor\n";
  arr = temp_arr;
}

int main(){

  vector<int> arr;
  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(3);
  Implement object_1;
  Implement object_2;
  Implement object_3(arr);
  Implement object_4 = object_3;
  cout << "Last element of vector in object 3 -> " << object_3.arr.back() << endl;
  object_3.arr.pop_back();
  cout << "Last element of vector in object 4 -> " << object_4.arr.back() << endl;
  return 0;
}
