/*
 * Problem statement: Rank(r) of a number = 1 + number of elements strictly greater
 *                    than that number. Given an unsorted array with distinct elements
 *                    and a rank R, find the element with rank R.
 * Data structure used: Ramdomized partition
 * Worst Case:    O(n^2)
 * Sample Input:  6 3
 *                10 2 1 4 5 6
 * Sample Output:
 */
#include <iostream>
#include <ctime>
using namespace std;

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}


int partition(int arr[],int low, int high){
  int i = (low - 1);
  int pivot = arr[high];
  for (int j = low; j <= high - 1; j++){
        if (arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int randomFindRank(int arr[],int i, int j, int r){

  if(i<=j){
    srand(time(0));
    int p = rand()%(j-i+1) + i;
    //Swapping and keeping the randomized pivot at the last
    swap(&arr[p],&arr[j]);
    int k = partition(arr,i,j);
    if(j-k+1 == r)
      return arr[k];
    else if(r < j-k+1)
      return randomFindRank(arr,k+1,j,r);
    else
      return randomFindRank(arr,i,k-1,r-(j-k+1));
  }
}

int main(){

  int r = 4;
  int arr[] = {10,2,1,4,5,6};
  int n = sizeof(arr)/sizeof(arr[0]);
  int ans = randomFindRank(arr,0,n-1,r);
  cout << "The element with rank " << r << " is " << ans << endl;
  return 0;
}
