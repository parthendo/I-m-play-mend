/*
 * Problem Statement: Given an array of integers, find i and j such that
 * 1. i != j
 * 2. |A[i]-A[j]| is maximum
 */
#include <cstdio>
#include <climits>
#include <iostream>
using namespace std;

int main(){

  int t; cin >> t;
  while(t--){
    int n;  cin >> n;
    int arr[n+5];
    for(int i=0;i<n;i++)  cin >> arr[i];
    int mx=INT_MIN, mxi, mn=INT_MAX, mni;
    for(int i=0;i<n;i++){
      if(arr[i]>mx){
        mx = arr[i];
        mxi = i;
      }
    }
    for(int i=0;i<n;i++){
      if(arr[i]<mn){
        mn = arr[i];
        mni = i;
      }
    }
    if(mxi!=mni)
      cout << "Max diffrence is " << mx-mn << " at " << mxi << " " << mni << endl;
    else
      cout << "No such elements available\n";
  }
  return 0;
}
