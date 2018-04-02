#include<stdio.h>
#include<string.h>
#include<limits.h>

//SJF pre-emptive without arrival time

typedef struct process{
        int processID;
        int burstTime;
}process;
int partition(process array[],int low,int high){
        int i=low,j=high;
        process pivot=array[high];
        while(i<j){
                while(array[i].burstTime<pivot.burstTime)
                        i++;
                while(array[j].burstTime>=pivot.burstTime)
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
void SJF(process array[],int n){
        int totalwaitingtime=0,i,totalbursttime=0,totalturnaroundtime=0;
        for(i=0;i<n;i++){
                int turnaroundtime=0,waitingtime=0;
                if(i>0)
                        waitingtime=totalwaitingtime+array[i-1].burstTime;
                totalbursttime+=array[i].burstTime;
                turnaroundtime=(waitingtime+array[i].burstTime);
                totalturnaroundtime+=turnaroundtime;
                totalwaitingtime=waitingtime;
        }
        printf("average waiting time = %f\n",((float)totalwaitingtime/(float)n));
        printf("average response time =%f \n",((float)totalwaitingtime/(float)n));
        printf("average turn around time = %f\n",((float)totalturnaroundtime/(float)n));
}



int main(){
        int n,i;
        process array[100];
        printf("enter number of processes\n");
        scanf("%d",&n);
        printf("enter process ID and burst time of %d processes\n",n);
        for(i=0;i<n;i++)
                scanf("%d%d",&array[i].processID,&array[i].burstTime);
        quicksort(array,0,n-1);
        SJF(array,n);
        return 0;
}
