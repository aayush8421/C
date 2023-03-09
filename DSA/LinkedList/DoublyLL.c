#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node * prev;
    int data;
    struct node * next;
};

void linkedListTraversal(struct node * head){
    struct node * ptr = head;
    printf("The elements are:\n");
    while(ptr->next!=NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n",ptr->data);
    printf("The reversed elements are:\n");
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->prev;
    }
}

struct node * create(int n){
    struct node * head,* ptr,* p;
    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter the elements:\n");
    scanf("%d",&(head->data));
    head -> prev = NULL;
    head -> next = NULL;
    ptr = head;
    for(int i=1;i<n;i++){
        p = (struct node *)malloc(sizeof(struct node));
        scanf("%d",&(p->data));
        p -> prev = NULL;
        p -> next = NULL;
        ptr -> next = p;
        p -> prev = ptr;
        ptr = p;
    }
    return head;
}

int main(){
    int n;
    printf("Enter the no of elements in linked list\n");
    scanf("%d",&n);
    struct node * head = create(n);
    linkedListTraversal(head);
}