#include<stdio.h>
#include<stdlib.h>

//structure of the node
struct node{
	int data;
	struct node* link;
}*top=NULL;

//isEmpty function
int isEmpty()
{
	if(top==NULL)
	return 1;
	else
	return 0;
}

//push function
void push(int data){
	struct node* newNode;
	newNode=malloc(sizeof(newNode));
	if(newNode==NULL)
	{
		printf("stack overflow");
		exit(1);
	}
	newNode->data=data;
	newNode->link=NULL;
	newNode->link=top;
	top=newNode;
}


//pop function
int pop(){
	struct node* temp;
	temp=top;
	if(isEmpty())
	{
		printf("stack underflow");
		exit(1);
	}
	int val=temp->data;
	top=top->link;
	free(temp);
	temp=NULL;
	return val;
}

//peek function
int peek(){
	if(isEmpty())
	{
		printf("stack overflow");
		exit(1);
	}
	return top->data;
}

//print function
void print()
{
	struct node* temp;
	temp=top;
	if(isEmpty())
	{
		printf("stack underflow");
		exit(1);
	}
	printf("the stack elements are:\n");
	while(temp){
		printf("%d\n", temp->data);
		temp=temp->link;
	}
	printf("\n");
}

int main()
{
	int choice,data;
	while(1)
	{
		printf("\n");
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.print the top element\n");
		printf("4.print all the element of the stack\n");
		printf("5.quit\n");
		printf("please enter your choice\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
			printf("enter the element to be pushed: ");
			scanf("%d",&data);
			push(data);
			printf("%d is pushed on top of the stack",data);
			break;
			case 2:
			data=pop();
			printf("deleted element is %d\n", data);
            break;
			case 3:
			printf("the topmost element of the stack is %d\n", peek());
			break;
			case 4:
			print();
			break;
			case 5:
			exit(1);
			default:
			printf("wrong choice\n");
		}
	}
	return 0;
}