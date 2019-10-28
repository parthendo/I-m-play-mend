/*
 * Problem statement: Given an array, create another array which contains the index such that:
 *                -> The index is as minimum as possible
 *                -> Value at that index >= Value at current index for each valid index in the array.
 * Data structure used: Stack
 * Worst Case:    O
 * Sample Input: 11
 *               48 93 12 748 63 7 4 73 98 64 41
 * Sample Output: 1 3 3 11 7 7 7 8 11 11 11
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> compute(int arr[],int n){
  stack<int> stk;
  vector<int> ans(n+4);
  stk.push(0);
  for(int i=1;i<n;i++){
    while(!stk.empty() && arr[i]>arr[stk.top()]){
      ans[stk.top()] = i;
      stk.pop();
    }
    stk.push(i);
  }
  while(!stk.empty()){
    ans[stk.top()] = n;
    stk.pop();
  }
  return ans;
}

int main(){
  int n;  cin >> n;
  int arr[n+5];
  for(int i=0;i<n;i++)  cin >> arr[i];
  vector<int> answer = compute(arr,n);
  for(int i=0;i<n;i++)
    cout << answer[i] << " ";
  cout << endl;
  return 0;
}
