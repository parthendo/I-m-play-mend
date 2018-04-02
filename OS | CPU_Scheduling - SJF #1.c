#include <stdio.h>
#include <stdlib.h>

//SJF nonpreemtive without arrival time

int partition(int arr[],int l,int h){

    int pivot = arr[h];
    int i = l-1,j,t;
    for(j=l;j<h;j++){

      if(arr[j]<=pivot){
        i++;
        t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
      }
    }
    t = arr[i+1];
    arr[i+1] = arr[h];
    arr[h] = t;
    return (i+1);
}

//Quicksort code
void sort(int arr[],int l,int r){

    if(l<r){

      int p = partition(arr,l,r);
      sort(arr,l,p-1);
      sort(arr,p+1,r);
    }
}

int main(void){

    //Declaration and input
    int n,i,currentTime = 0;
    float waitTime = 0.0f;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    int *arr = (int*)malloc(sizeof(int)*n);
    printf("Enter the burst time of processes\n");
    for(i=0;i<n;i++){
      scanf("%d",&arr[i]);
    }
    sort(arr,0,n-1);
    for(i = 0;i<n;i++){

        printf("Process Burst time : %d\tProcess wait time : %d\tProcess turn around time : %d\n",arr[i],((int)waitTime),arr[i]+((int)waitTime));
        waitTime = waitTime + (float)arr[i];
    }
    printf("\nAverage wait time : %.3f\n\n", waitTime/(float)n);
    return 0;
}
