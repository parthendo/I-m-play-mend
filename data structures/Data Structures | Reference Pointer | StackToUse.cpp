#include <stdio.h>
#include <stdlib.h>

typedef struct node{

	int val;
	struct node* next;
}node;

void push(node* &top,int n){

	node* temp = (node*)malloc(sizeof(node));
	temp->val = n;
	temp->next = top;
	top = temp;
}

int pop(node* &top){

	int value = top->val;
	node* temp = top;
	top = top->next;
	free(temp);
	return value;
}

int isEmpty(node* top){

	if(top == NULL)
		return 1;
	else
		return 0;
}

int TOP(node* top){

	if(isEmpty(top)){
		printf("Stack is empty\n");
		return -1;
	}
	else
		return top->val;
}

void display(node* top){

	node* temp = top;
	while(temp!=NULL){

		printf("%d\n",temp->val);
		temp = temp->next;
	}
} 
