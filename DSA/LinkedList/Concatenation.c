#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

void traverseLinkedList(struct node * ptr){
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct node * concatenation(struct node * p,struct node * q){
    struct node * p1 = p;
    while(p1->next!=NULL){
        p1 = p1 -> next;
    }
    p1 -> next = q;
    return p;
}

struct node * create(int n){
    struct node * head,* ptr,* ptr1;
    head = (struct node*)malloc(sizeof(struct node));
    printf("Enter the elements:\n");
    scanf("%d",&(head->data));
    head->next = NULL;
    ptr = head;
    for(int i = 1;i<n;i++)
    {
        ptr1 = (struct node*)malloc(sizeof(struct node));
        scanf("%d",&(ptr1->data));
        ptr1->next = NULL;
        ptr->next = ptr1;
        ptr = ptr1;
    }
    return head;
}

int main(){
    int n,m;
    printf("Enter the no of elements in 1st linked list\n");
    scanf("%d",&n);
    struct node * p = create(n);
    printf("The 1st linked list elements:\n");
    traverseLinkedList(p);
    printf("Enter the no of elements in 2nd linked list\n");
    scanf("%d",&m);
    struct node * q = create(m);
    printf("The 2nd linked list elements:\n");
    traverseLinkedList(q);
    printf("The merged linked list elements:\n");
    p = concatenation(p,q);
    traverseLinkedList(p);

}