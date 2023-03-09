#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int rear;
    int front;
    int * arr;
};

int isEmpty(struct queue *q){
    if(q->rear == q->front){
        return 1;
    }
    return 0;
}

int isFull(struct queue *q){
    if(q->rear == q->size-1){
        return 1;
    }
    return 0;
}

void display(struct queue* q)
{
	if(isEmpty(q))
	{
		printf("Queue underflow\n");
		return;
	}
	printf("\nThe Queue Elements are : \n");
	for(int i=q->front+1 ; i<=q->rear ; i++)
	{
		printf("%d  ",q->arr[i]);
	}
	printf("\n");
}

void enqueue(struct queue *q,int val){
    if(isFull(q)){
        printf("Queue overflow\n");
    }
    else{
        q->rear++;
        q->arr[q->rear] = val;
        // printf("%d added to the queue\n",val);
    }
}

int dequeue(struct queue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("Queue underflow\n");
        return a;
    }
    q->front++;
    a = q->arr[q->front];
    return a;
}

int main(){
    struct queue * q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 100;
    q->rear = q->front = -1;
    q->arr = (int *)malloc(q->size*sizeof(int));

    while(1)
	{
        printf("Enter your choice\n");
		printf("1. Add a element in Queue\n");
        printf("2. Delete from the Queue\n");
        printf("3. Display the Queue Elements\n");
        printf("4. Exit\n");
		int choice;
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nEnter the element to be added\n");
					int x;
					scanf("%d",&x);
					enqueue(q,x);
					break;
					
			case 2: dequeue(q);
					break;
					
			case 3: display(q);
					break;
					
			case 4: exit(0);
					break;
					
			default: printf("\nInvalid Choice...Try Again\n");
					
		}
	}
}