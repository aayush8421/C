#include<stdio.h>
#include<stdlib.h>

typedef struct stackelements{
    int item;
    struct stackelements *next;
}stackelements;
typedef struct stack{
    stackelements *top;
}stack;
void push(int a,stack *s)
{
    stackelements *x;
    x=(stackelements*)malloc(sizeof(stackelements));
    x->item=a;
    x->next=s->top;
    s->top=x;
}
int pop(stack *s)
{
    stackelements *t;
    if(s->top==NULL)
    {
        printf("Stack is empty");

    } 
    
    t=s->top;
    s->top=s->top->next;
    free(t);
    return 1;
}
void traversal(stack *s)
{
    if(s->top==NULL)
    {
        printf("Stack underflow");
        return;
    }
    stackelements *temp=s->top;
    printf("Your Elements are: \n");
    while(temp!=NULL)
    {
        printf("%d\n",temp->item);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    stack *s=(stack *)malloc(sizeof(stack));
    s->top=NULL;
    int choice,data;
	while(1)
	{
		printf("\n");
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.print all the element of the stack\n");
		printf("4.quit\n");
		printf("please enter your choice");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
			printf("enter the element to be pushed: ");
			scanf("%d",&data);
			push(data,s);
			printf("%d is pushed on top of the stack",data);
			break;
			case 2:
			data=pop(s);
			printf("deleted element is %d\n", data);
            break;
			case 3:
			print();
			break;
			case 4:
			exit(1);
			default:
			printf("wrong choice\n");
		}
	}
	return 0;
}