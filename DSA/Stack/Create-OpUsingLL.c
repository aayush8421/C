#include<stdio.h>
#include<stdlib.h>

struct stack{
    int data;
    struct stack * next;
};

struct stack * top = NULL;

void display(){
    struct stack * n = top;
    if(n==NULL)
    printf("Stack is empty\n");
    else{
        while(n!=NULL){
            printf("%d\n",n->data);
            n = n->next;
        }
    }
}

int isEmpty(){
    if(top==NULL)
    return 1;
    else
    return 0;
}

int isFull(){
    struct stack * n = (struct stack *)malloc(sizeof(struct stack));
    if(n==NULL)
    return 1;
    else
    return 0;
}

struct stack * push(int value){
    if(isFull()){
        printf("Stack overflow");
        return top;
    }
    else{
        struct stack * n = (struct stack *)malloc(sizeof(struct stack));
        n->data = value;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(){
    if(isEmpty()){
        printf("Stack underflow");
        return -1;
    }
    else{
        struct stack * n = top;
        int x = n->data;
        top = (top)->next;
        free(n);
        return x;
    }
}

int peek(int index){
    struct stack * n=top;
    for(int i=0;(i<index-1 && n!=NULL);i++){
        n = n->next;
    }
    if(n==NULL)
    return -1;
    else
    return n->data;
}

int stackTop(){
    return top->data;
}

int stackBottom(){
    struct stack * n = top;
    while(n->next!=NULL){
        n=n->next;
    }
    return n->data;
}

int main(){
    // struct stack * top = NULL;

    // top = push(7);
    // top = push(8);
    // top = push(9);
    // display();

    // printf("Topmost element: %d\n",stackTop());
    // printf("Bottom-most element: %d\n",stackBottom());

    // printf("The deleted :%d\n",pop());
    // printf("The deleted :%d\n",pop());
    // printf("The deleted :%d\n",pop());
    // display();

    // printf("Element at position 2: %d",peek(2));

    while(1){
        int choice;
        printf("Enter your choice\n");
        printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display top element\n");
		printf("4.Display stack\n");
		printf("5.Quit\n");
        scanf("%d",&choice);
        int data;
        switch(choice){
            case 1:
            printf("Enter the value to be pushed into the stack\n");
            scanf("%d",&data);
            top = push(data);
            printf("%d pushed into thr stack\n",data);
            break;
            case 2:
            printf("%d is popped out of the stack\n",pop());
            break;
            case 3:
            printf("The top of stack is %d\n",stackTop());
            break;
            case 4:
            printf("The stack elements:\n");
            display();
            break;
            case 5:
            exit(1);
            default:
            printf("Wrong choice!!!!Try again\n");
        }
    }
}