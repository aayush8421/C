#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int * arr;
};

void display(struct stack * ptr){
    for(int i=ptr->top;i>=0;i--){
        printf("%d\n",ptr->arr[i]);
    }
}
//checks whether stack is empty or not O(1)
int isEmpty(struct stack * ptr){
    if(ptr->top==-1)
    return 1;
    else
    return 0;
}
//checks whether stack is full or not O(1)
int isFull(struct stack * ptr){
    if(ptr->top==ptr->size-1)
    return 1;
    else
    return 0;
}
//pushes an element into the stack O(1)
void push(struct stack * ptr,int value){
    if(isFull(ptr)){
        printf("Stack Overflow\n");
        printf("Cannot push %d into the stack\n",value);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=value;
        printf("%d pushed into thr stack\n",value);
    }
}
//pops an element out of the stack O(1)
int pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}
//return the value at a specific position of stack O(1s)
int peek(struct stack * ptr,int i){
    if(ptr->top-i+1<0){
        printf("Not a valid position");
        return -1;
    }
    else{
        return ptr->arr[ptr->top-i+1];
    }
}
//returns topmost stack element O(1)
int stackTop(struct stack * ptr){
    return ptr->arr[ptr->top];
}
//retuurn bottomost stack element O(1)
int stackBottom(struct stack * ptr){
    return ptr->arr[0];
}

int main(){
    //creation of stack
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
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
            push(s,data);
            break;
            case 2:
            printf("%d is popped out of the stack\n",pop(s));
            break;
            case 3:
            printf("The top of stack is %d\n",stackTop(s));
            break;
            case 4:
            printf("The stack elements:\n");
            display(s);
            break;
            case 5:
            exit(1);
            default:
            printf("Wrong choice!!!!Try again\n");
        }
    }

}

