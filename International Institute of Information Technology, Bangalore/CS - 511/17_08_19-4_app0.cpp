/*
 * Problem Statement: Given an array of integers, find i and j such that
 * 1. i < j
 * 2. A[j]-A[i] is maximum
 * Approach: Divide and Conquer
 * Space Complexity: O(1)
 * Time Complexity: O(n^2)
 *
 * Input File: file_17_08_19-4.txt 
 * Output:
 * Maximum difference is 997043
 * Maximum difference is 990891
 * Maximum difference is 191411
 */
#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

int main(){
  FILE *fp = fopen("file_17_08_19-4.txt","r");
  int t;  fscanf(fp,"%d",&t);
  while(t--){
    int n;  fscanf(fp,"%d",&n);
    int arr[n+5];
    for(int i=0;i<n;i++) fscanf(fp,"%d",&arr[i]);
    int maxDiff = INT_MIN;
    for(int i=0;i<n-1;i++){
      for(int j=i+1;j<n;j++){
        if(arr[j]-arr[i]>maxDiff)
          maxDiff = arr[j]-arr[i];
      }
    }
    cout << "Maximum difference is " << maxDiff << endl;
  }
  return 0;
}
