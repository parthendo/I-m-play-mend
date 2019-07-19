/*
Testing program: C accesses memory in row major format and according to page size, 
				 if we access in row major format, less time shall be required due to 
				 less page faults.
*/
#include <time.h>
#include <stdio.h>
#define MAX 20000

int arr[MAX][MAX];

int main(){

	int i,j,sum = 0;
	time_t t1,t2;
	(void)time(&t1);
	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++)
			//Row Major Access
			//sum+=arr[i][j];
			//Column Major Access
			sum+=arr[j][i];
	(void)time(&t2);
	printf("The time taken in row major format to access the array is %lf seconds\n",(double)(t2-t1));
	return 0;
}