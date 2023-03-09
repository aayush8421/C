#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack
{
	int *arr;
	int max;
	int top;
}Stack;

Stack* createStack(int size)
{
	Stack* s=(Stack*)malloc(sizeof(Stack));
	s->top=-1;
	s->max=size;
	s->arr=(int*)malloc(sizeof(int)*s->max);
	
	return s;
}
int isDigit(char ch)
{
	return (ch>='0' && ch<='9');
}
int peek(Stack* s)
{
	return s->arr[s->top];
}

void push(Stack* s,int x)
{
	s->arr[++s->top]=x;
}

int pop(Stack* s)
{
	return s->arr[s->top--];
}

void EvalPrefix(char* exp)
{
	Stack *s=createStack(strlen(exp));
	for (int i=strlen(exp)-1 ; i>=0 ; i--)
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
					push(s,v1+v2);
					break;
				case '-':
					push(s,v1-v2);
					break;
				case '*':
					push(s,v1*v2);
					break;
				case '/':
					push(s,v1/v2);
					break;
				case '^':
					push(s,v1^v2);
					break;
			}
		}
	}
	printf("\n%d\n",peek(s));
	
}


int main()
{
    // char exp[] = "+4-*325";
    char exp[100];
    gets(exp);
	EvalPrefix(exp);
    return 0;
}