#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

void linkedListTraversal(struct node * ptr){
    printf("The elements:\n");
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    // struct node * head,* second,* third;
    // head = (struct node*)malloc(sizeof(struct node));
    // second = (struct node*)malloc(sizeof(struct node));
    // third = (struct node*)malloc(sizeof(struct node));

    // head->data = 7;
    // head->next = second;

    // second->data = 11;
    // second->next = third;
    
    // third->data = 66;
    // third->next = NULL;
    
    int m;
    printf("Enter the no. of nodes:\n");
    scanf("%d",&m);
    struct node * head,* ptr,* ptr1;
    head = (struct node*)malloc(sizeof(struct node));
    printf("Enter the elements:\n");
    scanf("%d",&(head->data));
    head->next = NULL;
    ptr = head;
    for(int i = 1;i<m;i++)
    {
        ptr1 = (struct node*)malloc(sizeof(struct node));
        scanf("%d",&(ptr1->data));
        ptr1->next = NULL;
        ptr->next = ptr1;
        ptr = ptr1;
    }

    linkedListTraversal(head);
}