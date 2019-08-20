#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){

  FILE* fp = fopen("Test/17_08_19-2.txt","r");
  int t; fscanf(fp,"%d",&t);
  while(t--){
    int n,k;
    fscanf(fp,"%d %d",&n,&k);
    int arr[n+5];
    for(int i=0;i<n;i++)  fscanf(fp,"%d",&arr[i]);
    sort(arr,arr+n);
    int var = arr[0],c = 1,ans = -1;
    for(int i=1;i<n;i++){
      if(var == arr[i]) c++;
      else if(c >= (floor(n/k)+1)){ans = var;break;}
      else{
        var = arr[i];
        c = 1;
      }
    }
    if(c >= (floor(n/k)+1) && ans == -1) ans = arr[n-1];
    if(ans == -1) cout << "No majority element found!\n";
    else          cout << ans << " is a majority element!\n";
  }
  return 0;
}
