#include<stdio.h>
typedef struct process
{
        int processID;
        int burstTime;
        int arrivalTime;
}process;

int partition(process array[],int low,int high)
{
        int i=low,j=high;
        process pivot=array[high];
        while(i<j)
        {
                while(array[i].arrivalTime<pivot.arrivalTime)
                        i++;
                while(array[j].arrivalTime>=pivot.arrivalTime)
                        j--;
                if(i<j)
                {
                        process temp=array[i];
                        array[i]=array[j];
                        array[j]=temp;
                }
        }
        array[high]=array[i];
        array[i]=pivot;
        return i;
}

void quicksort(process array[],int low,int high)
{
        int pivot;
        if(low<high)
        {
                pivot=partition(array,low,high);
                quicksort(array,low,pivot-1);
                quicksort(array,pivot+1,high);
        }
}

void FCFS(process array[],int n)
{
        int totalwaitingtime=0,totalbursttime=0,totalturnaroundtime=0,i,currentTime=array[0].arrivalTime,waitingtime=0;
        for(i=0;i<n;i++)
        {
                if(array[i].arrivalTime<currentTime)
                        waitingtime=currentTime-array[i].arrivalTime;
                else
                        waitingtime=0;
                totalbursttime+=array[i].burstTime;
                totalwaitingtime+=waitingtime;
                if(array[i].arrivalTime>currentTime)
                        currentTime=array[i].arrivalTime+array[i].burstTime;
                else
                currentTime+=array[i].burstTime;
        }
        totalturnaroundtime=totalwaitingtime+totalbursttime;
        printf("average waiting time = %f\n",((float)totalwaitingtime/(float)n));
        printf("average response time = %f\n",((float)totalwaitingtime/(float)n));
        printf("average turn around time = %f\n",((float)totalturnaroundtime/(float)n));
}

int main()
{
        int n,i;
        process array[100];
        printf("enter number of processes\n");
        scanf("%d",&n);
        printf("enter process ID,arrival time and burst time of %d processes\n",n);
        for(i=0;i<n;i++)
                scanf("%d%d%d",&array[i].processID,&array[i].arrivalTime,&array[i].burstTime);
        quicksort(array,0,n-1);
        FCFS(array,n);
        return 0;
}
