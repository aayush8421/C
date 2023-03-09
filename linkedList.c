#include<stdio.h>
#include<stdlib.h>

//NODE DECLARATION
typedef struct node{
    int element;
    struct node* next;
}node;

//CREATION OF NODE
node* create(int n)
{
    node *p, *q, *r;
    int i;
    p = (node*)malloc(sizeof(node*));
    scanf("%d",&(p->element));
    p->next = NULL;
    q = p;
    for(i = 0;i<n-1;i++)
    {
        r = (node*)malloc(sizeof(node*));
        scanf("%d",&(r->element));
        r->next = NULL;
        q->next = r;
        q = r;
    }
    return p;
}

//INSERTION AT THE iTH INDEX
void insertlist(struct node *p, struct node *t, int i)
{
	int j;
	struct node *q,*x;
	if(i==0)
	{
		t->next=p;
		p=t;
	}
	q=p;
	for(j=1;j<i&&q!=NULL;j++)
	q=q->next;
	if(q==NULL&&i>0) return;
	t->next=q->next;
	q->next=t;
}

//DELETION OF THE iTH INDEX
void deletlist(node *p, int i)
{
	node *x,*y;
	int j;
	y=p;
	if (i==0)
	{
		p=p->next;
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
	if(x==NULL&&i>0) 
    return;
	y->next=x->next;
	x->next=NULL;
	free(x);
    }
}

//PRINTING THE LIST
void traversal(node* p)
{
    node* t;
    t = p;
    while(p != NULL)
    {
        printf("%d",(p->element));
        p = p->next;
    }
    printf("\n");
    p = t;
}

//REVERSING THE LIST
node* reverse(node* p)
{
    node *l, *q, *n;
    q = p;
    l = NULL;
    n = q->next;
    while(q->next != NULL)
    {
        q->next = l;
        l = q;
        q = n;
        n = q->next;
    }
    q->next = l;
    return q;
}

//MERGING TWO LINKED LISTS
node* concatenation(node* p,node* q)
{
    node* r;
    if(p == NULL)
    p = q;
    else
    {
        r = p;
        while(r->next!=NULL)
        {
            r = r->next;
        }
        r->next = q;
    }
    return p;
}

int main()
{
    int choice;
    int n1;
    int n2;
    int n3,i3;
    int n4;
    int n5;
    int n6,m6;
    while(1)
    {
        printf("Enter:\n");
        printf("1.Creation\n");
        printf("2.Insertion\n");
        printf("3.Deletion\n");
        printf("4.Print\n");
        printf("5.Reverse\n");
        printf("6.Concatenation\n");
        printf("7.Circular Linked List\n");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
            printf("Enter the no of elements in linked list:\n");
            scanf("%d",&n1);
            node* p1 = create(n1);
            printf("List has been created\n");
            break;

            case 2:
            // printf("Enter the no of elements in linked list:\n");
            // scanf("%d",&n2);
            // node* p2 = create(n2);
            printf("Before inserting:\n");
            traversal(p1);
            node *a;
            a=(node*)malloc(sizeof(node));
            printf("Which element you want to insert");
            scanf("%d",&a->element);
            int j;
            printf("In which index you want to insert");
            scanf("%d",&j);
            insertlist(p1, a, j);
            printf("After insertion your linked list elements are: \n");
            traversal(p1);
            break;

            case 3:
            // printf("Enter the no of elements in linked list:\n");
            // scanf("%d",&n3);
            // node* p3 = create(n3);
            printf("Before Deletion:\n");
            traversal(p1);
            printf("Enter index where you want to delete\n");
            scanf("%d",&i3);
            deletlist(p1,i3);
            printf("After Deletion:\n");
            traversal(p1);
            break;

            case 4:
            // printf("Enter the no of elements in linked list:\n");
            // scanf("%d",&n4);
            // node* p4 = create(n4);
            printf("The Linked List:\n");
            traversal(p1);
            break;

            case 5:
            // printf("Enter the no of elements in linked list:\n");
            // scanf("%d",&n5);
            // node* p5 = create(n5);
            printf("The Linked List:\n");
            traversal(p1);
            printf("The reversed Linked List\n");
            node* z5 = reverse(p1);
            traversal(z5);
            break;

            case 6:
            printf("Enter the no of elements in 1st linked list:\n");
            scanf("%d",&n6);
            node* p6 = create(n6);
            printf("Enter the no of elements in 2nd linked list:\n");
            scanf("%d",&m6);
            node* q6 = create(m6);
            node* z6 = concatenation(p6,q6);
            printf("The new linked list\n");
            traversal(z6);
            break;

            case 7:
            break;

            default:
            printf("Wrong Choice\n");
            break;
        }
    }
}