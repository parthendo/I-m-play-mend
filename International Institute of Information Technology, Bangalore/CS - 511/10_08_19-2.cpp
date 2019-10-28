/*
 * Problem Statement: Implement a data structure which supports the two functionalities in minimum possible complexity:
 * Add(x):	Add element _x_ to the collection O(logn)
 * DeleteM():	Return the median of the collection and delete it. O(logn)
 *
 * Data Structure: Heap
 */
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

priority_queue< int > maxHeap;
priority_queue< int,vector<int>,greater<int>  > minHeap;

pair<int,int> Add(int x,pair<int,int> cnt){

  int mx_size = cnt.first;
  int mn_size = cnt.second;
  if(mx_size == mn_size){
    maxHeap.push(x);
    mx_size++;
  }
  else{
    int top = maxHeap.top();
    if(top > x){
      maxHeap.pop();
      minHeap.push(top);
      maxHeap.push(x);
      mn_size++;
    }
    else{
      minHeap.push(x);
      mn_size++;
    }
  }
  return {mx_size,mn_size};
}

pair<int,int> DeleteM(pair<int,int> cnt){

  int mx_size = cnt.first;
  int mn_size = cnt.second;
  int ans = maxHeap.top();
  maxHeap.pop();
  mx_size--;
  if(mx_size < mn_size){
    mn_size--;
    mx_size++;
    maxHeap.push(minHeap.top());
    minHeap.pop();
  }
  cout << "Median is " << ans << endl;
  return {mx_size,mn_size};
}

int main(){
  int q;  cin >> q;
  pair<int,int> cnt;
  cnt = {0,0};
  while(q--){
    int x;  cin >> x;
    if(x == 1){
      int y;  cin >> y;
      cnt = Add(y,cnt);
    }
    else{
      cnt = DeleteM(cnt);
    }
  }
  return 0;
}
