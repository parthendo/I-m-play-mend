#include <stdio.h>
#include <stdlib.h>

typedef struct node{

	int val;
	struct node *next;
}node;

void insert(node* &front,node* &rear,int n){

	node* temp = (node*)malloc(sizeof(node));
	temp->val = n;
	temp->next = NULL;
	if(rear == NULL){

		rear = temp;
		front = temp;
	}
	else{

		rear->next = temp;
		rear = temp;
	}
}

int delet(node* &front, node* &rear){

	if(front == NULL){

		printf("Queue is empty | Program will end");
		exit(1);
	}
	node* temp = (node*)malloc(sizeof(node));
	temp = front;
	int n = front->val;
	front = front->next;
	free(temp);
	if(front == NULL)
		rear = NULL;
	return n;
}

void display(node* front,node* rear){

	if(front == NULL)
		printf("Queue is empty\n");
	else{

		node* itr = front;
		do{
			printf("%d ",itr->val);
			itr = itr->next;
		}while(itr!=rear->next);
		printf("\n");
	}
}

int Front(node* front){

	if(front == NULL){

		printf("Queue is empty ");
		return -1;
	}
	else
		return front->val;
}

int main(){

	node *front,*rear;
	front = NULL;
	rear = NULL;
	int choice,n;
	printf("Implementation of QUEUE data structure\n");
	while(1){

		printf("Enter 1 to insert an element in the queue\n");
		printf("Enter 2 to delete an element from the queue\n");
		printf("Enter 3 to display the queue\n");
		printf("Enter 4 to find the front in the queue\n");
		printf("Enter any number apart from the above to quit\nChoice ");
		scanf("%d",&choice);
		if(choice == 1){

			printf("Enter the value ");
			scanf("%d",&n);
			insert(front,rear,n);
		}
		else if(choice == 2){

			printf("The element deleted off the queue is %d\n",delet(front,rear));
		}
		else if(choice == 3){

			printf("The queue is as follows ==> ");
			display(front,rear);
		}
		else if(choice == 4){

			printf("The element in the front is %d\n",Front(front));
		}
		else 
			break;
	}
	return 0;
}