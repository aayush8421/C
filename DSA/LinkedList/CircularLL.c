#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

void display(struct node * head){
    struct node * ptr = head;
    do{
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
}

struct node * insertAtFirst(struct node * head,int data){
    struct node * p = head;
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr -> data = data;
    while(p->next != head){
        p = p->next;
    }
    //At this point p is pointing to the last node of circularLL
    ptr -> next = head;
    head = ptr;
    p -> next = head;
    return head;
}
//insert at index will remain the same as in normal LL
struct node * insertAtIndex(struct node * head,int data,int index){
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    struct node * p = head;
    for(int i = 1;i < index-1;i++){
        p = p->next;
    }
    ptr->next = p->next; 
    p->next = ptr;
    return head;
}
//insert at last
struct node * insertAtLast(struct node * head,int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr -> data = data;
    struct node * p = head;
    while(p -> next != head){
        p = p->next;
    }
    //At this point p is pointing to the last node of circularLL
    p->next = ptr;
    ptr->next = head;
    return head;
}
//delete at first
struct node * deleteAtFirst(struct node * head){
    struct node * ptr = head;
    struct node * p = head;
    while(p->next != head){
        p = p->next;
    }
    p->next = ptr->next;
    head = head->next;
    printf("Deleted Element: %d\n",ptr->data);
    free(ptr);
    return head;
}
//deletion at index
struct node * deletionAtIndex(struct node *head,int index){
    struct node * ptr = head;
    for(int i=1;i<index-1;i++){
        ptr = ptr -> next;
    }
    struct node * p = ptr->next;
    ptr -> next = p -> next;
    printf("Deleted Element: %d\n",(p->data));
    free(p);
    return head;
}
//delete at last
struct node * deleteAtLast(struct node * head){
    struct node * ptr = head;
    struct node * p = head;
    while(ptr->next!=head){
        p = ptr;
        ptr = ptr->next;
    }
    p->next = head;
    printf("Deleted Element: %d",ptr->data);
    free(ptr);
    return head;
}

struct node * create(int n){
    struct node * head, * ptr, * ptr1;
    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter the elements:\n");
    scanf("%d",&(head->data));
    head -> next = NULL;
    ptr = head;
    for(int i = 1;i<n;i++){
        ptr1 = (struct node *)malloc(sizeof(struct node));
        scanf("%d",&(ptr1->data));
        ptr1 -> next = NULL;
        ptr -> next = ptr1;
        ptr = ptr1;
    }
    ptr -> next = head;
    return head;
}

int main(){
    // int n;
    // printf("Enter the no of elements in linked list\n");
    // scanf("%d",&n);
    // struct node * head = create(n);
    struct node * head;
    // printf("The linked list elements:\n");
    // linkedListTraversal(head);
    // // int data,index;
    // // printf("Enter the value to be inserted:\n");
    // // scanf("%d",&data);
    // // printf("Enter the index where to be inserted:\n");
    // // scanf("%d",&index);
    // // head = insertAtIndex(head,data,index);
    // // head = insertAtFirst(head,data);
    // // head = insertAtLast(head,data);

    // // head = deleteAtFirst(head);
    // printf("hhguygyjj");
    // head = deleteAtLast(head);
    // printf("The linked list elements:\n");
    // linkedListTraversal(head);

    printf("-----You have entered Circular Linked List operations-----\n");
    int cl;
    int e1 = 1;
    while(e1==1){
        printf("Enter your choice\n");
        printf("============\n");
        printf("1. Creation\n");
        printf("2. Insertion\n");
        printf("3. Deletion\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("============\n");
        printf("\n");
        scanf("%d",&cl);
        int n,value,incl,index,decl;
        switch(cl){
            case 1:
            printf("Enter the number of nodes\n");
            scanf("%d",&n);
            head = create(n);
            printf("Circular Linked List created\n");
            printf("\n");
            break;
            case 2:
            printf("Circular Linked List before insertion:\n");
            display(head);
            printf("Enter the value to be inserted: ");
            scanf("%d",&value);
            printf("1. Insert at first\n");
            printf("2. Insert at index\n");
            printf("3. Insert at end\n");
            scanf("%d",&incl);
            switch(incl){
                case 1:
                head = insertAtFirst(head,value);
                printf("After insertion at first\n");
                display(head);
                break;
                case 2:
                printf("Enter the index where the value is to be inserted: ");
                scanf("%d",&index);
                head = insertAtIndex(head,value,index);
                printf("After insertion at index\n");
                display(head);
                break;
                case 3:
                head = insertAtLast(head,value);
                printf("After insertion at end\n");
                display(head);
                break;
            }
            break;
            case 3:
            printf("Linked List before deletion:\n");
            display(head);
            printf("1. Delete at first\n");
            printf("2. Delete at index\n");
            printf("3. Delete at end\n");
            scanf("%d",&decl);
            switch(decl){
                case 1:
                head = deleteAtFirst(head);
                printf("After deletion at first\n");
                display(head);
                break;
                case 2:
                printf("Enter the index where the value is to be deleted: ");
                scanf("%d",&index);
                head = deletionAtIndex(head,index);
                printf("After deletion at index\n");
                display(head);
                break;
                case 3:
                head = deleteAtLast(head);
                printf("After deletion at end\n");
                display(head);
                break;
            }
            break;
            case 4:
            printf("The Circular Linked List elements\n");
            display(head);
            break;
            case 5:
            e1=0;
            break;
            default:
            printf("Wrong choice!!!!Try again\n");
        }
    }
}