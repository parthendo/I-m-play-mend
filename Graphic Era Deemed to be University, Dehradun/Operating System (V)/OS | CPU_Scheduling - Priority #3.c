#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Priority scheduling non-pre-emptive with arrival time

typedef struct process{

	int BT,AT,pid,priority,wait,heapIn;
}process;

process heap[MAX];
int heapSize;

/*Partition code for quicksort*/
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

/*Quicksort code snippet*/
sort(process arr[],int l,int r){

	if(l<r){
	
		int p = partition(arr,l,r);
		sort(arr,l,p-1);
		sort(arr,p+1,r);
	}
}

/*Inserts an element in the heap*/
void insert(process element) {

    heapSize++;
    heap[heapSize] = element;
    int now = heapSize;
    while (heap[now / 2].priority > element.priority) {

        heap[now] = heap[now / 2];
        now /= 2;
    }
    heap[now] = element;
}

/*Deletes root from the heap*/
void delete() {

    process minElement, lastElement;
    int child, now;
    minElement = heap[1];
    lastElement = heap[heapSize--];
    for (now = 1; now * 2 <= heapSize; now = child) {

        child = now * 2;
        if (child != heapSize && heap[child + 1].priority < heap[child].priority) {

            child++;
        }
        if (lastElement.priority > heap[child].priority) {

            heap[now] = heap[child];
        }
        else{
            break;
        }
    }
    heap[now] = lastElement;
}

int main(void){

	int i,n,currentTime,pos;
	heapSize = 0;
	printf("\t\tPlease enter the number of processes\n\t\t");
	scanf("%d",&n);
	process *arr = (process*)malloc(sizeof(process)*n);
	printf("Please enter the burst time, arrival time and priority\n\t\t");
	for(i=0;i<n;i++){
	
		printf("%d%d%d",&arr[i].BT,&arr[i].AT,&arr[i].priority);
		arr[i].pid = i+1;
		arr[i].wait = 0;
		arr[i].heapIn = 0;
	}
	/*Sort with respect to arrival time*/
	sort(arr,0,n-1);
	currentTIme = arr[pos].AT;
	do{
		while(1){
			
			if(arr[pos].AT == currentTime){
				
				arr[pos].heapIn = currentTime;
				insert(arr[pos++]);
			}
			else
				break;
		}
		
		
		
	}while(currentTime!=arr[n-1].AT && heapSize!=0);
	
	return 0;
}
