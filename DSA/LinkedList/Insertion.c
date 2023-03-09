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
//insertion at first O(1)
struct node * insertAtFirst(struct node * head,int data){
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> next = head;
    head = ptr;
    return head;
}
//insertion at index O(n)
struct node * insertAtIndex(struct node * head,int data,int index){
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    struct node * p = head;
    for(int i = 1;i < index-1;i++){
        p = p->next;
        if(p==NULL){
            printf("Invalid index");
            break;
            return head;
        }
    }
    ptr->next = p->next; 
    p->next = ptr;
    return head;
}
//insertion at end O(n)
struct node * insertAtEnd(struct node * head,int data){
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    struct node * p = head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

int main(){
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
    int data,index;
    printf("Enter the value to be inserted:\n");
    scanf("%d",&data);
    printf("Enter the index where to be inserted:\n");
    scanf("%d",&index);
    // head = insertAtFirst(head,data);
    head = insertAtIndex(head,data,index);
    // head = insertAtEnd(head,data);
    linkedListTraversal(head);
}