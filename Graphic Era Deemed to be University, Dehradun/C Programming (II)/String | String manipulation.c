/*
 * Problem statement: Encrypt string as follows-> I/p: abcdabf O/p: a2b2c1d1f1 
 * TC: O(n)
 * SC: O(26) ~ O(1)
 */
 
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #define MAX 1000
 
 typedef struct node{
	 
	char strng;
	int value;
 }node;

 node* compute(char *str){
	 
	 int i,j,pos = 0,l = strlen(str);
	 node *arr = (node*)malloc(sizeof(node)*30);
	 for(i=0;i<l;i++){
		 int flag = 0;
		 for(j=0;j<pos;j++){
			if(str[i] == arr[j].strng){
				flag = 1;
				break;
			}
		 }
		 if(!flag){
			 arr[pos].strng = str[i];
			 arr[pos].value = 1;
			 pos++;
		 }
		 else{
			 arr[j].value+=1;
		 }
	 }
	arr[pos].strng = '1';
	return arr;
 }
 
 int main(){
	 
	int i,l;
	char str[MAX];
	node *arr;
	scanf("%s",str);
	arr = compute(str);
	l = (int)sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<26;i++){
		if(arr[i].strng=='1')
			break;
		printf("%c%d",arr[i].strng,arr[i].value);
	}
	printf("\n");
	return 0;
 }
