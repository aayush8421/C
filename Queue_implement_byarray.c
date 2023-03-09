//queue implemenetation by array
#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
	int *arr;
	int size;
	int front;
	int rear;
}Queue;

Queue* createQueue(int size)
{
	Queue* q=(Queue*)malloc(sizeof(Queue));
	q->size=size;
	q->front=-1;
	q->rear=-1;
	q->arr=(int*)malloc(sizeof(int)*q->size);
	printf("\nQueue of size of %d elements is created\n",size);
	
	return q;
}

int enqueue(Queue* q,int x)
{
	if(q->rear==q->size-1)
	{
		printf("\nQueue Overflow....So can't be added furthur\n");
		return 0;
	}
	q->rear++;
	q->arr[q->rear]=x;
	printf("\n%d is added in the queue\n",x);
	return 1;
}

int dequeue(Queue* q)
{
	if(q->front==q->rear)
	{
		printf("\nQueue underflow....So can't be deleted furthur\n");
		return 0;
	}
	q->front++;
	int x=q->arr[q->front];
	printf("\n%d is deleted from queue\n",x);
	if(q->front==q->rear)
	{
		q->front=-1;
		q->rear=-1;
	}
	return x;
	
}

void displayQueue(Queue* q)
{
	if(q->front==q->rear)
	{
		printf("\nQueue underflow....So nothing to Print\n");
		return;
	}
	printf("\nThe Queue Elements are : \n");
	for(int i=q->front+1 ; i<=q->rear ; i++)
	{
		int t=q->arr[i];
		printf("%d  ",t);
	}
	printf("\n");
}


int main()
{
	printf("\nYou are working with Queue Data Structure\n");
	Queue* q=NULL;
	while(1)
	{
		printf("\n1. Create A Queue\n2. Add a element in Queue\n3. Delete from the Queue\n4. Display the Queue Elements\n5. Exit\n\nEnter your choice\n");
		int choice;
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nEnter the size of Queue to be created\n");
					int size;
					scanf("%d",&size);
					q=createQueue(size);
					break;
			
			case 2: printf("\nEnter the element to be added\n");
					int x;
					scanf("%d",&x);
					enqueue(q,x);
					break;
					
			case 3: dequeue(q);
					break;
					
			case 4: displayQueue(q);
					break;
					
			case 5: exit(0);
					break;
					
			default: printf("\nInvalid Choice...Please Try Again\n");
					
		}
	}
	
	return 0;
}