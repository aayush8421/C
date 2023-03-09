// circular queue implementation by array....

#include<stdio.h>
#include<stdlib.h>

typedef struct CQueue
{
	int* arr;
	int max;
	int front;
	int rear;
	
}CQueue;

CQueue* createCQueue(int size)
{
	CQueue *q=(CQueue*)malloc(sizeof(CQueue));
	q->max=size;
	q->front=-1;
	q->rear=-1;
	q->arr=(int*)malloc(sizeof(int)*q->max);
	
	printf("\nA Circular Queue is created of size of %d elements\n",size);
	return q;
}


int addToQ(CQueue* q,int x)
{
	if(q->front==-1 && q->rear==-1)
	{
		q->front=0;
		q->rear=0;
		q->arr[q->rear]=x;
	}
	else if((q->rear+1)%q->max==q->front)
	{
		printf("\nQueue Overflow....So can't be added furthur\n");
		return 0;
	}
	else
	{
		q->rear=(q->rear+1)%q->max;
		q->arr[q->rear]=x;
		printf("\n%d is added in the Circular Queue\n",x);
		return 1;
	}
}

int delFromQ(CQueue* q)
{
	int x;
	if(q->rear==-1 && q->front==-1)
	{
		printf("Queue Underflow...so nothing to delete\n");
		return 0;
	}
	else if(q->rear==q->front)
	{
		x=q->arr[q->front];
		q->front=-1;
		q->rear=-1;
	}
	else
	{
		x=q->arr[q->front];
		q->front=(q->front+1)%q->max;
	}
	printf("\n%d is deleted from Circular Queue\n",x);
	return x;
	
}

void displayCQueue(CQueue* q)
{
	if(q->front==-1 || q->rear==-1)
	{
		printf("\nQueue is Empty...\n");
		return;
	}
	printf("\nThe Circular Queue Elements are : \n");
	printf("%d ",q->arr[q->front]);
	int i=(q->front+1)%q->max;
	while(i!=(q->rear+1)%q->max)
	{
		printf("%d ",q->arr[i]);
		i=(i+1)%q->max;
	}
	printf("\n");
	
}


int main()
{
	printf("\n-------\1You are working on Circular Queue-------\n");
	CQueue* q=NULL;
	while(1)
	{
		printf("\n1. Create A Circular Queue\n2. Insert A Element\n3. Delete from Queue\n4. Display Elements\n5. Exit\n\nEnter Your Choice\n");
		int choice;
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nEnter the size of Circular Queue\n");
					int size;
					scanf("%d",&size);
					q=createCQueue(size);
					break;
			case 2: printf("\nEnter the element to be added\n");
					int x;
					scanf("%d",&x);
					addToQ(q,x);
					break;
			case 3: delFromQ(q);
					break;
			case 4: displayCQueue(q);
					break;
			case 5: exit(0);
					break;
			default: printf("\nInvalid Choice....Please Try Again\n");
					break;
					
		}
	}
	
return 0;
}



