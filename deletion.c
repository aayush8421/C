#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
int element;
struct node *next;	
}node;
void traversal(struct node*ptr)
{
	struct node*t;
	t=ptr;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->element);
		ptr=ptr->next;
	}
	ptr=t;
}
void deletlist(struct node **p, int i)
{
	struct node *x,*y;
	int j;
	y=*p;
	if (i==0)
	{
		*p=y->next;
		free(y);
		return;
	}
	else
	{
		x=y->next;
		for(j=1;j<i&&x!=NULL;j++)
		{
			y=x;
			x=x->next;
		}
		if(x==NULL&&i>0) return;
		 y->next=x->next;
		 x->next=NULL;
		 free(x);
	}
}
int main()
{
	struct node *p,*q,*r;
	int i,n,j;
	printf("How many nodes are there in your linked list?");
	scanf("%d",&n);
	p=(struct node*)malloc(sizeof(struct node));
	scanf("%d",&p->element);
	p->next=NULL;
	q=p;
	for(i=0;i<n-1;i++)
	{
		r=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&r->element);
		r->next=NULL;
		q->next=r;
		q=r;
	}
	printf("Before deletion your linked list elements are: \n");
	traversal(p);
	printf("From which  index you want to delet the node");
	scanf("%d",&j);
	deletlist(&p,j);
	printf("After deletion your linked list elements are: \n");
	traversal(p);
}
