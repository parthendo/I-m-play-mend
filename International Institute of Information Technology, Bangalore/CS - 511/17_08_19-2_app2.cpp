/*
 * Problem Statement: Given a sequence of integers, find integers repeating (n/k)+1
 *                    number of times
 * Space Complexity: O(k)
 * Time Complexity: O(nk)
 */

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int bucket[1000][4];

int findIndex(int k,int n){
  int ans = -1;
  for(int i=0;i<k;i++)
    if(bucket[i][0] == n){
      ans = i;
      break;
    }
  return ans;
}

int toInput(int k){
  int ans = -1;
  for(int i=0;i<k;i++)
    if(bucket[i][0] == -1){
      ans = i;
      break;
    }
  return ans;
}

void reset(int k){
  for(int i=0;i<k;i++){
    if(bucket[i][1] == 0)
      bucket[i][0] = -1;
      bucket[i][1] = 0;
  }
}

void minusAll(int k){
  for(int i=0;i<k;i++){
    bucket[i][1]--;
  }
}

int main(){

  FILE* fp = fopen("Test/17_08_19-2.txt","r");
  int t;
  fscanf(fp,"%d",&t);
  while(t--){
    int n,k,count=0;
    fscanf(fp,"%d %d",&n,&k);
    int arr[n+5];
    for(int i=0;i<=k;i++) bucket[i][0] = -1, bucket[i][1] = 0;
    for(int i=0;i<n;i++)  fscanf(fp,"%d",&arr[i]);
    for(int i=0;i<n;i++){
      int idx = findIndex(k,arr[i]);
      if(idx == -1){
        idx = toInput(k);
        if(idx == -1){
          minusAll(k);
          reset(k);
        }
        else
          bucket[idx][0] = arr[i],bucket[idx][1] = 1;
      }
      else
        bucket[idx][1]++;
    }
    vector<int> ans;
    for(int i=0;i<k;i++){
      if(bucket[i][0]!=-1){
        int x = bucket[i][0];
        int c = 0;
        for(int i=0;i<n;i++)
          if(x == arr[i]) c++;
        if(c>=(n/k+1))
          ans.push_back(bucket[i][0]);
      }
      else
        break;
    }
    int l = ans.size();
    if(l == 0)
      cout << "No majority element found\n";
    else{
      for(int i=0;i<l;i++)
        cout << ans[i] << " ";
      cout << "is/are a majority element\n";
    }
  }
  return 0;
}
