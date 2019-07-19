#include<stdio.h>

//Priority scheduling with arrival time

typedef struct process
{
	int processID;
	int burstTime;
	int tempburstTime;
	int responsetime;
	int arrivalTime;
	int priority;
	int outtime;
	int intime;
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

void insert(process Heap[],process value,int *heapsize,int *currentTime)
{
	int start=*heapsize,i;
	Heap[*heapsize]=value;
	if(Heap[*heapsize].intime==-1)
		Heap[*heapsize].intime=*currentTime;
	++(*heapsize);
	while(start!=0 && Heap[(start-1)/2].priority>Heap[start].priority)
	{
		process temp=Heap[(start-1)/2];
		Heap[(start-1)/2]=Heap[start];
		Heap[start]=temp;
		start=(start-1)/2;
	}
}

void order(process Heap[],int *heapsize,int start)
{
	int smallest=start;
	int left=2*start+1;
	int right=2*start+2;
	if(left<*heapsize&&Heap[left].priority<Heap[smallest].priority)
		smallest=left;
	if(right<*heapsize&&Heap[right].priority<Heap[smallest].priority)
		smallest=right;
	if(smallest!=start)
	{
		process temp=Heap[smallest];
		Heap[smallest]=Heap[start];
		Heap[start]=temp;
		order(Heap,heapsize,smallest);
	}
}

process extractminimum(process Heap[],int *heapsize,int *currentTime)
{
	process min=Heap[0];
	if(min.responsetime==-1)
		min.responsetime=*currentTime-min.arrivalTime;
	--(*heapsize);
	if(*heapsize>=1)
	{
		Heap[0]=Heap[*heapsize];
		order(Heap,heapsize,0);
	}
	return min;
}

void scheduling(process Heap[],process array[],int n,int *heapsize,int *currentTime)
{
	if(heapsize!=0)
	{
		int i;
		process min=extractminimum(Heap,heapsize,currentTime);
		min.outtime=*currentTime+1;
		--min.burstTime;
		printf("process id = %d current time = %d\n",min.processID,*currentTime);
		if(min.burstTime>0)
			insert(Heap,min,heapsize,currentTime);
		else
		{
			int i;
			for(i=0;i<n;i++)
				if(array[i].processID==min.processID)
				{
					array[i]=min;
					break;
				}
		}
	}
}

void priority(process array[],int n)
{
	int totalwaitingtime=0,totalbursttime=0,totalturnaroundtime=0,i,insertedprocess=0,heapsize=0,currentTime=array[0].arrivalTime,totalresponsetime=0;
	process Heap[4*n];
	for(i=0;i<n;i++)
	{
		totalbursttime+=array[i].burstTime;
		array[i].tempburstTime=array[i].burstTime;
	}
	do
	{
		if(insertedprocess!=n)
		{
			for(i=0;i<n;i++)
			{
				if(array[i].arrivalTime==currentTime)
				{
					++insertedprocess;
					array[i].intime=-1;
					array[i].responsetime=-1;
					insert(Heap,array[i],&heapsize,&currentTime);
				}
			}
		}
		scheduling(Heap,array,n,&heapsize,&currentTime);
		++currentTime;
		if(heapsize==0&&insertedprocess==n)
			break;
	}while(1);
	for(i=0;i<n;i++)
	{
		totalresponsetime+=array[i].responsetime;
		totalwaitingtime+=(array[i].outtime-array[i].intime-array[i].tempburstTime);
		totalbursttime+=array[i].burstTime;
	}
	printf("average waiting time = %f\n",((float)totalwaitingtime/(float)n));
	printf("average response time =%f\n",((float)totalresponsetime/(float)n));
	printf("average turn around time = %f\n",((float)(totalwaitingtime+totalbursttime)/(float)n));
}

int main()
{
	int n,i;
	process array[190];
	scanf("%d",&n);
	printf("enter process ID,arrival time,process priority and burst time of %d processes\n",n);
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&array[i].processID,&array[i].arrivalTime,&array[i].priority,&array[i].burstTime);
	quicksort(array,0,n-1);
	priority(array,n);
	return 0;
}
