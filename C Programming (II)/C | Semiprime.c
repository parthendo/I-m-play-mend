#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

int seive_array[MAX];

void seive(){

	int i,j;
	seive_array[1] = 1;
	for(i=4;i<=MAX;i+=2)
		seive_array[i] = 1;
	for(i=3;i<=MAX;i+=2){
		if(seive_array[i] == 0){
			for(j=i*2;j<=MAX;j+=i)
				seive_array[j] = 1;
		}
	}
}

int main(){

	seive();
	int i,n;
	printf("Please enter the number\n");
	scanf("%d",&n);
	for(i=2;i<=n;i++){
		if(n%i == 0){
			if(seive_array[i] == 0 && seive_array[n/i] == 0){
				printf("%d --> Semiprime\n",n);
				return 0;
			}
		}
	}
	printf("%d --> Not-Semiprime\n",n);
	return 0;
}