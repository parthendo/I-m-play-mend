#include <stdio.h>
#include <string.h>
#include "Data Structures | StackToUse.cpp"
#define MAX 10000

int main(){

	char str[MAX];
	printf("Enter the string ");
	scanf("%s",str);
	int l = strlen(str);
	node* top = NULL;
	int i,flag = 1;
	for(i=0;i<l;i++){

		if(str[i] == '(')
			push(top,'(');
		else if(str[i] == ')' && isEmpty(top)){
			flag = 0;
			break;
		}
		else
			pop(top);
	}

	if(isEmpty(top) == 0)
		flag = 0;

	if(flag)
		printf("Parenthesis matched successfully!\n");
	else
		printf("Parenthesis did not match successfully!\n");
	return 0;
}