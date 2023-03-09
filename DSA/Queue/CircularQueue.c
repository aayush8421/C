#include<stdio.h>
#include<stdlib.h>
struct cqueue{
    int size;
    int rear;
    int front;
    int * arr;
};

int isEmpty(struct cqueue *q){
    if(q->rear == q->front){
        return 1;
    }
    return 0;
}

int isFull(struct cqueue *q){
    if((q->rear+1)%q->size == q->front){
        return 1;
    }
    return 0;
}

void display(struct cqueue* q)
{
	if(isEmpty(q))
	{
		printf("Queue underflow\n");
		return;
	}
	printf("\nThe Circular Queue Elements are : \n");
    int i=(q->front+1)%q->size;
	while(i!=(q->rear+1)%q->size)
	{
		printf("%d ",q->arr[i]);
		i=(i+1)%q->size;
	}
	printf("\n");
}

void enqueue(struct cqueue *q,int val){
    if(isFull(q)){
        printf("Queue overflow\n");
    }
    else{
        q->rear = (q->rear+1)%q->size;
        q->arr[q->rear] = val;
        printf("%d added to the Circular queue\n",val);
    }
}

int dequeue(struct cqueue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("Queue underflow\n");
        return a;
    }
    q->front = (q->front+1)%q->size;
    a = q->arr[q->front];
    printf("%d deleted from the Circular queue\n",a);
    return a;
}

int main(){
    struct cqueue * q = (struct cqueue *)malloc(sizeof(struct cqueue));
    q->size = 100;
    q->rear = q->front = 0;
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
					
			default: printf("\nInvalid Choice...Please Try Again\n");
					
		}
	}
}