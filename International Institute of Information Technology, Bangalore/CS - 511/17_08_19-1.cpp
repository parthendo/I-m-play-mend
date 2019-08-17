#include <cstdio>
#include <iostream>
using namespace std;

int main(){

  FILE* fp = fopen("file_17_08_19.txt","r");
  int n;
  fscanf(fp,"%d",&n);
  int arr[n+5];
  for(int i=0;i<n;i++)
    fscanf(fp,"%d",&arr[i]);
  int var = arr[0], c = 1;
  for(int i=1;i<n;i++){
    if(var == arr[i]) c++;
    else if(c>0)  c--;
    else  var = arr[i],c = 1;
  }
  c = 0;
  for(int i=0;i<n;i++){
    if(arr[i] == var) c++;
  }
  if(c>=(n/2+1))  cout << var << " is a majority element!\n";
  else            cout << "No majority element found!\n";
  return 0;
}
