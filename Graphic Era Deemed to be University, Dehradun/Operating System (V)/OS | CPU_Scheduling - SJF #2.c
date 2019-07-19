#include<stdio.h>
#include<string.h>
#include<limits.h>

//SJF non-preemptive with arrival time

typedef struct process{
        int processID;
        int inserted;
        int arrivalTime;
        int burstTime;
        int intime;
        int responsetime;
        int outtime;
        int turnaroundtime;
}process;
process extractminimum(process[],int*,int*);
void insertHeap(process value,process Heap[],int *heapsize,int *currentTime){
        Heap[*heapsize]=value;
        if(Heap[*heapsize].intime==-1)
                Heap[*heapsize].intime=*currentTime;
        int start=*heapsize;
        Heap[*heapsize].turnaroundtime=Heap[*heapsize].burstTime;
        ++(*heapsize);
        while(start!=0 && Heap[(start-1)/2].burstTime > Heap[start].burstTime){
                process temp=Heap[(start-1)/2];
                Heap[(start-1)/2]=Heap[start];
                Heap[start]=temp;
                start=(start-1)/2;
        }
}
int partition(process array[],int low,int high){

        int i=low,j=high;
        process pivot=array[high];
        while(i<j){

                while(array[i].arrivalTime<pivot.arrivalTime)
                        i++;
                while(array[j].arrivalTime>=pivot.arrivalTime)
                        j--;
                if(i<j){

                        process temp=array[i];
                        array[i]=array[j];
                        array[j]=temp;
                }
        }
        array[high]=array[i];
        array[i]=pivot;
        return i;
}

void quicksort(process array[],int low,int high){

        int pivot;
        if(low<high){

                pivot=partition(array,low,high);
                quicksort(array,low,pivot-1);
                quicksort(array,pivot+1,high);
        }
}

void order(int start,process Heap[],int *heapsize){

        int left=2*start+1;
        int right=2*start+2;
        int smallest=start;
        if(left<*heapsize&&Heap[start].burstTime>Heap[left].burstTime)
                smallest=left;
        if(right<*heapsize&&Heap[right].burstTime<Heap[smallest].burstTime)
                smallest=right;
        if(smallest!=start){

                process temp=Heap[start];
                Heap[start]=Heap[smallest];
                Heap[smallest]=temp;
                order(smallest,Heap,heapsize);
        }
}

process extractminimum(process Heap[],int *heapsize,int *currentTime){

        process min=Heap[0];
        --(*heapsize);
        if(min.responsetime==-1)
                min.responsetime=*currentTime-min.arrivalTime;
        if(*heapsize>=1){

                Heap[0]=Heap[*heapsize];
                int start=0;
                order(start,Heap,heapsize);
        }
        return min;
}

void scheduling(process Heap[],int n,process array[],int *heapsize,int *currentTime,int *totalwaitingtime)
{
        int i;
        process min=extractminimum(Heap,heapsize,currentTime);
        (*currentTime)=(*currentTime)+min.burstTime;
        min.outtime=(*currentTime);
        for(i=0;i<n;i++)
        if(array[i].processID==min.processID)
        {
                array[i]=min;
                break;
        }
}

void SJF(process array[],int n)
{
        int i,totalbursttime=0,totalturnaroundtime=0,processinserted=0,totalresponsetime=0;
        int heapsize=0,currentTime=array[0].arrivalTime,totalwaitingtime=0;
        process Heap[4*n];
        do
        {
                if(processinserted!=n)
                {
                        for(i=0;i<n;i++)
                        {
                                if(array[i].arrivalTime<=currentTime&&array[i].inserted==0)
                                {
                                        array[i].inserted=1;
                                        ++processinserted;
                                        array[i].intime=-1;
                                        array[i].responsetime=-1;
                                        insertHeap(array[i],Heap,&heapsize,&currentTime);
                                }
                        }
                }
                scheduling(Heap,n,array,&heapsize,&currentTime,&totalwaitingtime);
                if(heapsize==0&&processinserted==n)
                        break;
        }
        while(1);
        for(i=0;i<n;i++){

                totalwaitingtime+=(array[i].outtime-array[i].intime-array[i].burstTime);
                totalresponsetime+=array[i].responsetime;
                totalbursttime+=array[i].burstTime;
        }
        printf("average waiting time = %f\n",((float)totalwaitingtime/(float)n));
        printf("average response time =%f\n",((float)totalresponsetime/(float)n));
        printf("average turnaroundtime = %f\n",((float)(totalwaitingtime+totalbursttime)/(float)n));
}


int main(){

        int n,i;
        process array[100];
        printf("enter number of processes\n");
        scanf("%d",&n);
        printf("enter process ID,arrival time and burst time of %d processes\n",n);
        for(i=0;i<n;i++){

                scanf("%d%d%d",&array[i].processID,&array[i].arrivalTime,&array[i].burstTime);
                array[i].inserted=0;
        }
        quicksort(array,0,n-1);
        SJF(array,n);
        return 0;
}
