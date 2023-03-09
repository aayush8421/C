#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    int top;
    char * arr;
};
int isEmpty(struct stack * ptr){
    if(ptr->top==-1)
    return 1;
    else
    return 0;
}
int isFull(struct stack * ptr){
    if(ptr->top==ptr->size-1)
    return 1;
    else
    return 0;
}
void push(struct stack * ptr,char value){
    ptr->top++;
    ptr->arr[ptr->top]=value;
}
char pop(struct stack * ptr){
    int value = ptr->arr[ptr->top];
    ptr->top--;
    return value;
}
char stackTop(struct stack * ptr){
    return ptr->arr[ptr->top];
}

int precidence(char ch){
    if(ch == '^')
    return 3;
    else if(ch == '*'||ch =='/')
    return 2;
    else if(ch == '+'||ch =='-')
    return 1;
    else
    return 0;
}

int isOperator(char ch){
    if(ch >='a' && ch <='z' || ch >='A' && ch <='Z' || ch >='0' && ch <='9')
    return 0;
    else
    return 1;
}

char * inToPo(char * infix){
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = strlen(infix)+1;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size*sizeof(char));

    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else{
            if(infix[i] == '('){
                push(sp,infix[i]);
            }
            else if(infix[i] == ')'){
                while(stackTop(sp) != '(' && !isEmpty(sp)){
                    postfix[j] = pop(sp);
                    j++;
                }
                pop(sp);
            }
            else{
                while(precidence(infix[i])<=precidence(stackTop(sp))){
                    postfix[j] = pop(sp);
                    j++;
                }
                push(sp,infix[i]);
            }
            i++;
        }
    }
    while(!isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main(){
    // char * infix = "(A/(B-C)*D+E)";
    char * infix;
    printf("Enter the Infix Expression:-\n");
    gets(infix);
    printf("The Postfix expression is\n %s",inToPo(infix));
}