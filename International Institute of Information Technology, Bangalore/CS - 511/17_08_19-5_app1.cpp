/*
 * Problem Statement: Given an array of integers, find i and j such that
 * 1. i+L <= j
 * 2. A[j]-A[i] is maximum
 * Approach: Greedy Algorithm
 * Space Complexity: O(1)
 * Time Complexity: O(n)
 *
 * Input File: file_17_08_19-5.txt
 * Output:
 * Maximum difference is 998034
 * Maximum difference is 990891
 * Maximum difference is 189346
 */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;

int main(){
  FILE *fp = fopen("Test/17_08_19-5.txt","r");
  int t;  fscanf(fp,"%d",&t);
  while(t--){
    int n,l;  fscanf(fp,"%d %d",&n,&l);
    int arr[n+5];
    for(int i=0;i<n;i++) fscanf(fp,"%d",&arr[i]);
    int maxDiff = INT_MIN;
    int i = 0;
    for(int j=l;j<n;j++){
      maxDiff = max(maxDiff,arr[j]-arr[i]);
      if(arr[i]>arr[j])
        i = j-l+1;
    }
    cout << "Maximum difference is " << maxDiff << endl;
  }
  return 0;
}
