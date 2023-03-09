#include<stdio.h>
#include<stdlib.h>
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
void pop(struct stack * ptr){
    ptr->top--;
}
int matching(char * exp){
    //create and initialize stack
    struct stack * sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            push(sp,'(');
        }
        else if(exp[i]==')'){
            if(isEmpty(sp))
            return 0;
            pop(sp);
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    char * exp;
    exp = "(4-3)*(8))";
    if(matching(exp))
    printf("The parenthesis is matching\n");
    else
    printf("The parenthesis is not matching\n");
}