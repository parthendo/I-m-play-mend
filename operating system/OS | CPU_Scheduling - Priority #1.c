#include<stdio.h>

//Priority scheduling without arrival time

typedef struct process
{
	int processID;
	int burstTime;
	int priority;
}process;

int partition(process a[],int low,int high)
{
	int i=low,j=high;
	process pivot=a[high];
	while(i<j)
	{
		while(a[i].priority<pivot.priority)
			i++;
		while(a[j].priority>=pivot.priority)
			j--;
		if(i<j)
		{
			process temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	a[high]=a[i];
	a[i]=pivot;
	return i;
}

void quicksort(process a[],int low,int high)
{
	int pivot;
	if(low<high)
	{
		pivot=partition(a,low,high);
		quicksort(a,low,pivot-1);
		quicksort(a,pivot+1,high);
	}
}

void priority(process a[],int n)
{
	int i,totalwaitingtime=0,totalbursttime=0,currentTime=0;
	for(i=0;i<n;i++)
	{
	totalwaitingtime+=currentTime;
	totalbursttime+=a[i].burstTime;
	currentTime+=a[i].burstTime;
	printf("process ID=%d current time = %d\n",a[i].processID,currentTime);
	}
	printf("average waiting time = %f\n",((float)totalwaitingtime/(float)n));
	printf("average response time = %f\n",((float)totalwaitingtime/(float)n));
	printf("average burst time = %f\n",((float)totalbursttime/(float)n));
	printf("average turn around time = %f\n",((float)(totalwaitingtime+totalbursttime)/(float)n));
}

int main()
{
	int n,i;
	process a[100];
	scanf("%d",&n);
	printf("enter process ID,burst time and priority of %d processes\n",n);
	for(i=0;i<n;i++)
		scanf("%d%d%d",&a[i].processID,&a[i].burstTime,&a[i].priority);
	quicksort(a,0,n-1);
	priority(a,n);
	return 0;
}
