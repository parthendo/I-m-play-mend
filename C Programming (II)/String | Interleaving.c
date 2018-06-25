/*
 * Problem statement: Given three strings A,B & C. Find if C is an interleaving 
 * 					  of A and B. Interleaving, C has all characters of A and B 
 * 					  preserving the individual order of characters.
 * Sample Input: A = "pat" B = "arth" C = "parth"
 */ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10000

int inorder(char *A,char *C){
	int i,pos = 0,l = strlen(C);
	for(i=0;i<l;i++){
		
		if(C[i] == A[pos])
			pos++;
	}
	if(A[pos] == '\0')
		return 1;
	else
		return 0;
}

int main(){
	
	char A[MAX],B[MAX],C[MAX];
	scanf("%s %s %s",A,B,C);
	if(inorder(A,C) && inorder(B,C))
		printf("C is an interleaving of A and B\n");
	else
		printf("C is not an interleaving of A and B\n");
	return 0;
}
