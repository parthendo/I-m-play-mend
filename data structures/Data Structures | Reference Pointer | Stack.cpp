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

int main(){

	int n;
	node* top = NULL;
	while(1){

		printf("Press 1 to push a number\n");
		printf("Press 2 to pop a number\n");
		printf("Press 3 to view topmost member\n");
		printf("Press 4 to diplay stack\n");
		printf("Press 5 to quit\n");
		int ch;
		scanf("%d",&ch);
		if(ch == 1){

			printf("Enter the number\n");
			scanf("%d",&n);
			push(top,n);
		}
		else if(ch == 2)
			printf("Element popped is %d",pop(top));
		else if(ch == 3)
			printf("Topmost element is %d\n",TOP(top));
		else if(ch == 4)
			display(top);
		else
			break;
	}
	return 0;
}