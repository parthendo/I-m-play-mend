/*
 * Problem Statement: Count the number of inversion pairs in an array
 * Algorithm Used: Mergesort
 */

#include <iostream>
using namespace std;

long merge(long arr[],int l, int m, int r){
  int nl = m-l+1, nr = r-m;
  long L[nl+5],R[nr+5];
  for(int i=0;i<nl;i++)  L[i] = arr[l+i];
  for(int i=0;i<nr;i++)    R[i] = arr[m+i+1];
  long i = 0, j = 0, k = l, count = 0;
  while(i<nl && j<nr){
    if(L[i]<=R[j])  arr[k++] = L[i++];
    else count+=(nl-i), arr[k++] = R[j++];
  }
  while(i<nl) arr[k++] = L[i++];
  while(j<nr) arr[k++] = R[j++];
  return count;
}

long Mergesort(long arr[],int l,int r){
  long ctr = 0;
  if(l<r){
    //Prevents overflow
    int mid = l+(r-l)/2;
     ctr += Mergesort(arr,l,mid)+Mergesort(arr,mid+1,r)+merge(arr,l,mid,r);
  }
  return ctr;
}

int main(){

  int t;
  string str;
  cin >> t;
  getline(cin,str);
  while(t--){
    int n;  cin >> n;
    long arr[n+5];
    for(int i=0;i<n;i++)  cin >> arr[i];
    cout << Mergesort(arr,0,n-1) << endl;
    getline(cin,str);
  }
  return 0;
}
