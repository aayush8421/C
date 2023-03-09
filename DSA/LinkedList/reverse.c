#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

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

void traverseLinkedList(struct node * ptr){
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct node * reverse(struct node * head){
    
}