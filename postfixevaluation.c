#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack
{
	int *arr;
	int max;
	int top;
}Stack;

void push(Stack *s,int x)
{
	s->arr[++s->top]=x;
}
int pop(Stack *s)
{
	if(s->top==-1)
	return 0;
	else
	{
		int ch=s->arr[s->top--];
		return ch;
	}
}

int peek(Stack *s)
{
	return s->arr[s->top];
}

Stack* createStack(int size)
{
	Stack *s=(Stack*)malloc(sizeof(Stack));
	s->top=-1;
	s->max=size;
	s->arr=(int*)malloc(sizeof(int)*s->max);
	
	return s;
}

int isDigit(int x)
{
	return (x>='0' && x<='9');
}

void EvalPostfix(char* exp)
{
	Stack *s=createStack(strlen(exp));
	for(int i=0 ; i<exp[i]!='\0' ; i++)
	{
		if(isDigit(exp[i]))
		{
			push(s,exp[i]-'0');
		}
		else
		{
			int v1=pop(s);
			int v2=pop(s);
			
			switch(exp[i])
			{
				case '+':
					push(s,v2+v1);
					break;
				case '-':
					push(s,v2-v1);
					break;
				case '*':
					push(s,v2*v1);
					break;
				case '/':
					push(s,v2/v1);
					break;
				case '^':
					push(s,v2^v1);
					break;
					
			}
		}
	}
	printf("After evaluating the result is:\n");
	printf("%d",peek(s));
	
}

int main()
{
    // char exp[] = "2536+**5/2-";
    char * exp;
	printf("Enter the Postfix expression:\n");
    gets(exp);
	EvalPostfix(exp);
    return 0;
}