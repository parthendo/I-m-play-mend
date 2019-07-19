/*
 * Problem Statement: Given a string with non-repeating characters, find
 * 					  permutation of such string
 * Sample Input:
 * abc
 * Sample Output:
 * abc
 * acb
 * bac
 * bca
 * cba
 * cab
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;

void _swap(char &a, char &b){
	
	char t = a;
	a = b;
	b = t;
}

void permute(char *str,int n,int l){
	
	if(n==l){
		printf("%s\n",str);
	}
	for(int i=n;i<l;i++){
		_swap(str[n],str[i]);
		permute(str,n+1,l);
		_swap(str[n],str[i]);
	}
}

int main(){
	
	char str[MAX];
	int l = strlen(str);
	scanf("%s",str);
	//printf("%s\n",str);
	permute(str,0,l);
	return 0;
}
