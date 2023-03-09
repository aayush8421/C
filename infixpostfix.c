#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Stack{
    int top;
    int size;
    char *arr;
} Stack;

int isEmpty(Stack *s){
    if (s->top == -1)
        return 1;
    else
        return 0;
}
int push(Stack *s, char val){
    if (s->top == s->size - 1){
        return -1;
    }
    else{
        s->top++;
        s->arr[s->top] = val;
    }
}
char peek(Stack *s){
    return s->arr[s->top];
}
char pop(Stack *s){
    if (s->top == -1){
        printf("Empty\n");
    }
    else{
        char a;
        a = s->arr[s->top];
        s->top--;
        return a;
    }
}
int pressi(char ch){
    // if (ch == '(' || ch == ')')
    //     return 4;

    if (ch == '^')
        return 3;

    else if (ch == '*' || ch == '/')
        return 2;

    else if (ch == '+' || ch == '-')
        return 1;

    else
        return -1;
}
int checkOperator(char c){
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
        return 1;
    else
        return 2;
}
char *postfix(char *str, Stack *s){
    char *ans = (char *)malloc((strlen(str) + 1) * sizeof(char));
    int i = 0;
    int len = 0;
    while (str[i] != '\0'){
        char ch = str[i];
        int choice = checkOperator(ch);
        // printf("%d ", choice);
        switch (choice){
        case 1:
            ans[len] = ch;
            len++;
            i++;
            break;
        case 2:
            if (ch == '('){
                push(s, ch);
            }

            else if (ch == ')'){
                while (s->arr[s->top] != '(' && !isEmpty(s))
                {
                    char x = pop(s);
                    ans[len] = x;
                    len++;
                }
                pop(s);
            }
            else{
                while ((pressi(ch) <= pressi(s->arr[s->top])) && !isEmpty(s))
                {
                    char x = pop(s);
                    ans[len] = x;
                    len++;
                }
                push(s, ch);
            }
            i++;
            break;
        }
    }
    while (!isEmpty(s)){
        ans[len] = pop(s);
        len++;
    }

    ans[len] = '\0';
    // printf("\n%s\n", ans);
    return ans;
}
int main(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    s->size = 100;
    s->arr = (char *)malloc(s->size * sizeof(char));

    // char *str = "(A/(B-C)*D+E)";
	char str[100];
    printf("\nEnter the infix expression:-\n");
	gets(str);
    printf("The postfix expression of the entered infix expression:-\n");
    printf("\n%s", postfix(str, s));
    // ans ABC-/D*E+
}