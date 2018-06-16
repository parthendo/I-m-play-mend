/*
 * Problem Statement: Implement the functioning of Postifix Expression Evaluation
 *                    which supports multiple expressions such as +,-,/,*,^ and
 *                    multi-digit numbers too.
 * Sample Input: 3 4 + 1000 * 10 2 ^ /
 * Sample Output: 70
 */
#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

int toDigit(string str){

  int sum = 0, p = 0, l = str.length();
  for(int i=l-1;i>=0;i--)
    sum+=(pow(10,(p++))*(str[i]-'0'));
  return sum;
}

int postfixEval(string str){

  stack <int> stk;
  int lastPos = 0, number, l =str.length();
  bool flag = false;
  for(int i=0;i<l;i++){

    if(flag){
      if(str[i] == ' '){
        flag = false;
        if(str[lastPos]>='0' && str[lastPos]<='9'){
          number = toDigit(str.substr(lastPos,i-lastPos));
          stk.push(number);
        }
       else if(str[lastPos] == '+'){
         if(stk.empty()){

           cout<<"Invalid Expression\n";
           exit(1);
         }
         int number1 = stk.top();
         stk.pop();
         if(stk.empty())
          stk.push(number1);
         else{
           int number2 = stk.top();
           stk.pop();
           number1+=number2;
           stk.push(number1);
         }
       }
       else if(str[lastPos] == '-'){
         if(stk.empty()){

           cout<<"Invalid Expression\n";
           exit(1);
         }
         int number1 = stk.top();
         stk.pop();
         if(stk.empty())
          stk.push(-1*number1);
         else{
           int number2 = stk.top();
           stk.pop();
           number2-=number1;
           stk.push(number2);
         }
       }
       else if(str[lastPos] == '/'){
         if(stk.empty()){

           cout<<"Invalid Expression\n";
           exit(1);
         }
         int num1 = stk.top();
         stk.pop();
         if(stk.empty()){

           cout<<"Invalid Expression\n";
           exit(1);
         }
         int num2 = stk.top();
         stk.pop();
         num2/=num1;
         stk.push(num2);
       }
       else if(str[lastPos] == '*'){
         if(stk.empty()){

           cout<<"Invalid Expression\n";
           exit(1);
         }
         int num1 = stk.top();
         stk.pop();
         if(stk.empty()){

           cout<<"Invalid Expression\n";
           exit(1);
         }
         int num2 = stk.top();
         stk.pop();
         num2*=num1;
         stk.push(num2);
       }
       else if(str[lastPos] == '^'){
         if(stk.empty()){

           cout<<"Invalid Expression\n";
           exit(1);
         }
         int num1 = stk.top();
         stk.pop();
         if(stk.empty()){

           cout<<"Invalid Expression\n";
           exit(1);
         }
         int num2 = stk.top();
         stk.pop();
         num2 = pow(num2,num1);
         stk.push(num2);
       }
      }
      else{
        continue;
      }
    }
    else{
      if(str[i]!=' '){
        lastPos = i;
        flag = true;
      }
    }
  }
  return stk.top();
}

int main(){

  string str;
  cout << "Enter the expression\n";
  getline(cin,str);
  str += " ";
  cout << postfixEval(str) << endl;
  return 0;
}
