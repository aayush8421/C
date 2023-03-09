#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};
//traversal
void display(struct node * ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
//creation
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
//insertion at first
struct node * insertAtFirst(struct node * head,int data){
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> next = head;
    head = ptr;
    return head;
}
//insertion at index
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
//insertion at end
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
//deletion at first
struct node *deletionAtFirst(struct node * head){
    struct node * ptr = head;
    printf("Deleted Element: %d\n",(ptr->data));
    head = ptr->next;
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
//deletion at last
struct node * deletionAtLast(struct node *head){
    struct node * ptr = head;
    struct node * p = head;
    while(ptr->next!=NULL){
        p = ptr;
        ptr = ptr->next;
    }
    p->next = NULL;
    printf("Deleted Element: %d\n",(ptr->data));
    free(ptr);
    return head;
}
//reversal
struct node* reversal(struct node* p)
{
    struct node *l, *q, *n;
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
//concatenation
struct node * concatenation(struct node * p,struct node * q){
    struct node * p1 = p;
    while(p1->next!=NULL){
        p1 = p1 -> next;
    }
    p1 -> next = q;
    return p;
}


//cl creation
struct node * clcreate(int n){
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
//cl traversal
void cldisplay(struct node * head){
    struct node * ptr = head;
    do{
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
    printf("\n");
}
//cl insert at first
struct node * clinsertAtFirst(struct node * head,int data){
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
//cl insert at last
struct node * clinsertAtLast(struct node * head,int data){
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
//cl delete at first
struct node * cldeleteAtFirst(struct node * head){
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
//cl delete at last
struct node * cldeleteAtLast(struct node * head){
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

int main(){
    struct node * head;
    while(1){
        int choice;
        printf("Enter your choice\n");
        printf("=======================\n");
        printf("1. Singlely Linked List\n");
        printf("2. Circular Linked List\n");
        printf("3. Exit\n");
        printf("=======================\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("-----You have entered Singlely Linked List operations-----\n");
            int ll;
            int e = 1;
            while(e==1){
                printf("Enter your choice\n");
                printf("================\n");
                printf("1. Creation\n");
                printf("2. Insertion\n");
                printf("3. Deletion\n");
                printf("4. Display\n");
                printf("5. Reversal\n");
                printf("6. Concatenation\n");
                printf("7. Exit\n");
                printf("================\n");
                printf("\n");
                scanf("%d",&ll);
                int n;
                int value,inll;
                int index;
                int dell;
                int m;
                switch(ll){
                    case 1:
                    printf("Enter the number of nodes\n");
                    scanf("%d",&n);
                    head = create(n);
                    printf("Linked List created\n");
                    printf("\n");
                    break;
                    case 2:
                    printf("Linked List before insertion:\n");
                    display(head);
                    printf("Enter the value to be inserted: ");
                    scanf("%d",&value);
                    printf("1. Insert at first\n");
                    printf("2. Insert at index\n");
                    printf("3. Insert at end\n");
                    scanf("%d",&inll);
                    switch(inll){
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
                        head = insertAtEnd(head,value);
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
                    scanf("%d",&dell);
                    switch(dell){
                        case 1:
                        head = deletionAtFirst(head);
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
                        head = deletionAtLast(head);
                        printf("After deletion at end\n");
                        display(head);
                        break;
                    }
                    break;
                    case 4:
                    printf("The Linked List elements:\n");
                    display(head);
                    break;
                    case 5:
                    printf("Linked list before reversing\n");
                    display(head);
                    head = reversal(head);
                    printf("Linked list after reversing\n");
                    display(head);
                    break;
                    case 6:
                    if(head!=NULL){
                        printf("The Linked List elements:\n");
                        display(head);
                        printf("This linked list already exists\n");
                    }
                    else{
                        printf("Enter the number of nodes in 1st linked list\n");
                        scanf("%d",&n);
                        struct node * head = create(n);
                        printf("The 1st Linked List elements:\n");
                        display(head);
                    }
                    printf("Enter the number of nodes in 2nd linked list\n");
                    scanf("%d",&m);
                    struct node * p = create(m);
                    printf("The 2nd Linked List elements:\n");
                    display(p);
                    head = concatenation(head,p);
                    printf("The merged linked list\n");
                    display(head);
                    break;
                    case 7:
                    e=0;
                    break;
                    default:
                    printf("Wrong Choice!!!Try again\n");
                }
            }
            break;
            case 2:
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
                    head = clcreate(n);
                    printf("Circular Linked List created\n");
                    printf("\n");
                    break;
                    case 2:
                    printf("Circular Linked List before insertion:\n");
                    cldisplay(head);
                    printf("Enter the value to be inserted: ");
                    scanf("%d",&value);
                    printf("1. Insert at first\n");
                    printf("2. Insert at index\n");
                    printf("3. Insert at end\n");
                    scanf("%d",&incl);
                    switch(incl){
                        case 1:
                        head = clinsertAtFirst(head,value);
                        printf("After insertion at first\n");
                        cldisplay(head);
                        break;
                        case 2:
                        printf("Enter the index where the value is to be inserted: ");
                        scanf("%d",&index);
                        head = insertAtIndex(head,value,index);
                        printf("After insertion at index\n");
                        cldisplay(head);
                        break;
                        case 3:
                        head = clinsertAtLast(head,value);
                        printf("After insertion at end\n");
                        cldisplay(head);
                        break;
                    }
                    break;
                    case 3:
                    printf("Linked List before deletion:\n");
                    cldisplay(head);
                    printf("1. Delete at first\n");
                    printf("2. Delete at index\n");
                    printf("3. Delete at end\n");
                    scanf("%d",&decl);
                    switch(decl){
                        case 1:
                        head = cldeleteAtFirst(head);
                        printf("After deletion at first\n");
                        cldisplay(head);
                        break;
                        case 2:
                        printf("Enter the index where the value is to be deleted: ");
                        scanf("%d",&index);
                        head = deletionAtIndex(head,index);
                        printf("After deletion at index\n");
                        cldisplay(head);
                        break;
                        case 3:
                        head = cldeleteAtLast(head);
                        printf("After deletion at end\n");
                        cldisplay(head);
                        break;
                    }
                    break;
                    case 4:
                    printf("The Circular Linked List elements\n");
                    cldisplay(head);
                    break;
                    case 5:
                    e1=0;
                    break;
                    default:
                    printf("Wrong choice!!!!Try again\n");
                }
            }
            break;
            case 3:
            exit(1);
            break;
            default:
            printf("Wrong coice");
        }
    }
}