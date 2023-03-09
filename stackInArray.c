#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int arr[10];
    int top;
}stack;

int push(int a,stack *x)
{
    if(x->top == 10)
    return 0;
    else
    {
        x->top += 1;
        x->arr[x->top] = a;
        return 1;
    }
}

int pop(stack *x,int *a)
{
    if(x->top == 1)
    return;
    else{
        *a = x->arr[x->top];
        x->top = x->top - 1;
        return 1;
    }
}