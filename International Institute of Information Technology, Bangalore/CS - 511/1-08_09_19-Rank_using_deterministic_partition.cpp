#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindRank(int arr[],int i,int j,int r);
int Swape(int arr[],int i,int j){
  int t = arr[i];
  arr[i] = arr[j];
  arr[j] = t;
}
int cei(float x){
  return x+1;
}
int min(int a,int b){
  if(a<=b)  return a;
  return b;
}

void bubbleSort(int arr[], int L,int R){
    int i, j;
    for (i = L; i < R; i++)
      for (j = L; j < R-i-1; j++)
        if (arr[j] > arr[j+1])
          Swape(arr,j,j+1);
}

int pivot(int arr[],int I,int J){
  int n = J-I+1;
  int leader = 0;
  printf("%d %d\n",I,J);
  //Traversing N/5 arrays
  for(int i=I;i<=J;i+=5){
    int N = min(n-i,5);
    bubbleSort(arr,i,i+N);
    Swape(arr,leader,i+N/2);
    leader++;
  }
  for(int i=I;i<=J;i++)
    printf("%d ",arr[i]);
  printf("\n");
  return (FindRank(arr,I,I+n/5,(n+9)/10));
}

int partition (int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high-1; j++){
        if (arr[j] <= pivot){
            i++;
            Swape(arr,i,j);
        }
    }
    Swape(arr,i+1,high);
    return (i + 1);
}

int FindRank(int arr[],int i,int j,int r){
  int p;
  if(i!=j && r>0)
    p = pivot(arr,i,j);
  else
    p = i;
  printf("Median element = %d\n",p);
  Swape(arr,j,p);
  p = partition(arr,i,j);
  int trank = j-p+1;
  if(trank == r)
    return arr[p];
  else if(trank>r)
    return FindRank(arr,i,trank-1,r-(j-trank+1));
  else
    return FindRank(arr,trank+1,j,r);
}

int main(){

  FILE *fp = fopen("sample0.txt","r");
  int n,r, arr[1000005];
  fscanf(fp,"%d",&n);
  for(int i=0;i<n;i++)
    fscanf(fp,"%d",&arr[i]);
  fscanf(fp,"%d",&r);
  printf("The element corresponding to rank %d is %d\n",r,FindRank(arr,0,n-1,r));
  return 0;
}
