/*
 * Problem statement: Given two binary strings and an integral value denoting the
 *                    length, find if a pattern of the given length exists in both
 *                    of the strings or not? |string1| + |string2| <= 1000000
 * Algorithm Used: Rabin Karp with chaining
 * Worst Case:
 * Sample Input:
 * Sample Output:
 *
 * Problems: The questions isn't working for modulus 5 and 7 and implementation
 * only works for 0 and 1.
 */
#include <iostream>
#include <vector>
#define mod 13
using namespace std;

int compute(string s1,string s2,int l, int st2,vector<int> hashtable[],int txtx2){
  int x = hashtable[txtx2].size(),count = 0;
  if(x>0){
    for(int i=0;i<x;i++){
      int j,idx = hashtable[txtx2][i];
      for(j=0;j<l;j++){
        if(s2[st2 + j]!=s1[idx+j])
          break;
      }
      if(j == l)
        count++;
    }
  }
  return count;
}

int extended_Rabin_Karp(string s1,string s2, int l, int base){
  int n1 = s1.length();
  int n2 = s2.length();
  int c = 1,txtx1 = 0, txtx2 = 0, ans = 0;

  /*
    Now for a binary pattern with length L, the maximum value can be pow(2,3)-1
    but the values present in the hashtable will be [0,mod-1]
    */
  vector<int> hashtable[mod+5]; //+5 for safety
  // For the first L indeces
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

  ans+=compute(s1,s2,l,0,hashtable,txtx2);
  for(int i=l;i<n2;i++){
    txtx2 = (txtx2-(c*(s2[i-l]-'0')))%mod;
    txtx2 = (base*txtx2 + (s2[i]-'0'))%mod;
    ans += compute(s1,s2,l,i-l+1,hashtable,txtx2);
  }
  return ans;
}


//Driver function
int main(){

  int ans =  extended_Rabin_Karp("011011","110111",3,2);
  cout << "Total number of patterns found are " << ans << endl;
  return 0;
}
