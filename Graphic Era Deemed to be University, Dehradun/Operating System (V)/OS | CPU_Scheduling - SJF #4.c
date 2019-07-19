/*SJF pre-emptive with arrival time*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100000
typedef struct process{

    int BT,AT,pos;
    int heapin,heapout;
}process;

process heap[MAX];
int heapSize;

int partition(process arr[],int l,int h){

    process pivot = arr[h],t;
    int i = l-1,j;
    for(j=l;j<h;j++){

      if(arr[j].AT<=pivot.AT){

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
void sort(process arr[],int l,int r){

    if(l<r){

      int p = partition(arr,l,r);
      sort(arr,l,p-1);
      sort(arr,p+1,r);
    }
}






//Inserts an element in the heap
void insert(process element) {

    heapSize++;
    heap[heapSize] = element;
    int now = heapSize;
    while (heap[now / 2].BT > element.BT) {

        heap[now] = heap[now / 2];
        now /= 2;
    }
    heap[now] = element;
}

//Deletes root from the heap
void delete() {

    process minElement, lastElement;
    int child, now;
    minElement = heap[1];
    lastElement = heap[heapSize--];
    for (now = 1; now * 2 <= heapSize; now = child) {

        child = now * 2;
        if (child != heapSize && heap[child + 1].BT < heap[child].BT) {

            child++;
        }
        if (lastElement.BT > heap[child].BT) {

            heap[now] = heap[child];
        }
        else{
            break;
        }
    }
    heap[now] = lastElement;
}

//Could have used binary search for optimization
int search(process arr[],int l,int r,int id){

  int i;
  for(i=l;i<r;i++){

    if(arr[i].pos == id)
      break;
  }
  return i;
}


int main(void){

    //Declaration and input
    int n,i,currentTime,pos,local;
    float waitTime = 0.0f;
    heapSize = 0;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    process *arr = (process*)malloc(sizeof(process)*n);
    printf("Enter the burst time and arrival time of processes\n");
    for(i=0;i<n;i++){
      scanf("%d %d",&arr[i].BT,&arr[i].AT);
      arr[i].pos = i+1;
      arr[i].heapin = 0;
      arr[i].heapout = 0;
    }
    sort(arr,0,n-1);
    currentTime = arr[0].AT;
    pos = 0;
    do{
	  while(1){
	if(arr[pos].AT == currentTime){
            arr[pos].heapin = currentTime;
            insert(arr[pos++]);
          }
          else
            break;}
        currentTime++;
        process prc = heap[1];
        delete();
        printf("Process ID : %d\tProcess arrival time : %d\tProcess burst time :%d\n",prc.pos,prc.AT,prc.BT);
        prc.BT--;
        if(prc.BT>0){
          insert(prc);
        }
        else{
          local = search(arr,0,pos,prc.pos);
          arr[local].heapout = currentTime;
        }
    }while(heapSize != 0);
    printf("\n\tSummary\t\n");
    for(i=0;i<n;i++){

        printf("Process ID : %d\tProcess wait time : %d\n",
                  arr[i].pos,arr[i].heapout-arr[i].heapin);
        waitTime+=(arr[i].heapout-arr[i].heapin);
    }
    printf("\nAverage wait time : %.3f\n",waitTime/((float)n));
    return 0;
}
