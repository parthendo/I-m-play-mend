/*
 * Problem statement: Given a text string and a pattern string, we need to search
 *                    the number of occurances of that pattern in that string.
 * Algorithm Used: Rabin Karp
 * Worst Case:    O(mn)
 * Sample Input: 11011 101
 * Sample Output: 1
 *
 * Problems: The questions isn't working for modulus 5 and 7.
 */
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#define mod 11
using namespace std;

/*  We first convert the text and the pattern into denary form and compute the
    hash value. If the hash value is same, only then we do the brute matching */
int Rabin_Karp(string txt,string pat, int base){
  int m = txt.length();
  int n = pat.length();

  vector<int> index;
  int c = 1, patx = 0, txtx = 0;
  for(int i=0;i<n;i++){
    // Computing C would reduce the task of calculating 2^x saving log(n) time each time
    c = (c * base)%mod;
    patx = (patx*base + pat[i])%mod;
    txtx = (txtx*base + txt[i])%mod;
  }
  c /= base;
  for(int i=n;i<m;i++){
    if(patx == txtx){
      int j;
      for(j=0;j<n;j++){
        if(pat[j] != txt[i-n+j])
          break;
      }
      if(j == n){
        index.push_back(i-n);
      }
    }
    txtx = (txtx-c*txt[i-n])%mod;
    txtx = (base*txtx + txt[i])%mod;
  }
  int l = index.size();
  if(l>0){
    cout << "Pattern exists at \n";
    for(int i=0;i<l;i++)
      cout << index[i] << " ";
  }
  cout << endl;
  return l;
}
//Driver Function
int main(){

  Rabin_Karp("110110110111","1011",2);
  return 0;
}
