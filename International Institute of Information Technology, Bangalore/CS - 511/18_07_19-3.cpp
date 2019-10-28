/*
 * Problem statement: Given two binary strings, find the length of the longest
 *                    pattern present in both the strings.
 * Algorithm Used: Rabin Karp with chaining and binary search
 * Worst Case:
 * Sample Input:
 * Sample Output:
 */
#include <iostream>
#include <vector>
#define mod 101
using namespace std;

vector<int> hashtable[mod+5];

bool computer(string s1,string s2,int l, int st2,int txtx2){
  int x = hashtable[txtx2].size();
  if(x>0){
    for(int i=0;i<x;i++){
      int j,idx = hashtable[txtx2][i];
      for(j=0;j<l;j++){
        if(s2[st2 + j]!=s1[idx+j])
          break;
      }
      if(j == l)
        return true;
    }
  }
  return false;
}

bool findPattern(string s1,string s2, int n1, int n2, int l, int base){
  int c = 1,txtx1 = 0, txtx2 = 0;
  for(int i=0;i<mod;i++)  hashtable[i].clear();
  for(int i=0;i<l;i++){
    c = (c*base)%mod;
    txtx1 = ((base*txtx1+(s1[i]-'0')))%mod;
    txtx2 = ((base*txtx2+(s2[i]-'0')))%mod;
  }
  hashtable[txtx1].push_back(0);
  c/=base;
  // Roll over hashing
  for(int i=l;i<n1;i++){
    txtx1 = (txtx1-(c*(s1[i-l]-'0')))%mod;
    txtx1 = (base*txtx1 + (s1[i]-'0'))%mod;
    hashtable[txtx1].push_back(i-l+1);
  }
  if(computer(s1,s2,l,0,txtx2)) return true;
  for(int i=l;i<n2;i++){
    txtx2 = (txtx2-(c*(s2[i-l]-'0')))%mod;
    txtx2 = (base*txtx2 + (s2[i]-'0'))%mod;
    if(computer(s1,s2,l,i-l+1,txtx2))
      return true;
  }
  return false;
}


int maximum_length_match(string str1,string str2, int base){
  int l1 = str1.length();
  int l2 = str2.length();
  if(l1>l2){
    string temp = str1; str1 = str2; str2 = temp;
    int t = l1; l1 = l2; l2 = t;
  }
  bool temp = findPattern(str1,str2,l1,l2,l1,base);
  if(temp == true)
    return l1;
  else{
    int low = 0, high = l1, mid = 0;
    while(low<=high){
      mid = (low+high)/2;
      int temp = findPattern(str1,str2,l1,l2,mid,base);
      if(temp == true){
        low = mid+1;
      }
      else{
        high = mid-1;
      }
    }
    return mid;
  }
}

int main(){
  cout << "The maximum length available is " << maximum_length_match("11011111","101101",2) << endl;
  return 0;
}
