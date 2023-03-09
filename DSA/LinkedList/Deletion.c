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
//deletion at first O(1)
struct node *deletionAtFirst(struct node * head){
    struct node * ptr = head;
    printf("Deleted Element: %d\n",(ptr->data));
    head = ptr->next;
    free(ptr);
    return head;
}
//deletion at index O(n)
struct node * deletionAtIndex(struct node *head,int index){
    struct node * ptr = head;
    for(int i=1;i<index-1;i++){
        ptr = ptr -> next;
        if(ptr->next==NULL){
            printf("Invalid Index\n");
            return head;
            break;
            // return head;
        }
    }
    struct node * p = ptr->next;
    ptr -> next = p -> next;
    free(p);
    return head;
}
//deletion at last O(n)
struct node * deletionAtLast(struct node *head){
    // struct node * ptr = head;
    // struct node * p = head;
    // while(ptr->next!=NULL){
    //     p = ptr;
    //     ptr = ptr->next;
    // }
    // p->next = NULL;
    // free(ptr);
    // return head;

    struct node * p,* q;
    p=head;
    q=head->next;
    while(q->next!=NULL){
        p=q;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}
//deletion at a specific value O(n)
struct node * deletionAtValue(struct node * head,int value){
    struct node * ptr = head;
    struct node * p = head->next;
    while(p->data != value && p->next == NULL){
        ptr = ptr->next;
        p = p->next;
    }
    if(p->data == value){
        ptr -> next = p -> next;
        free(p);
    }
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
    // head = deletionAtFirst(head);
    // int index;
    // printf("Enter the index:\n");
    // scanf("%d",&index);
    // head = deletionAtIndex(head,index);
    head = deletionAtLast(head);
    // int value;
    // printf("Enter the value:\n");
    // scanf("%d",&value);
    // head = deletionAtValue(head);
    linkedListTraversal(head);
}



//Code with harry's code
struct node * deleteFirst(struct node * head){
    struct node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct node * deleteAtIndex(struct node * head, int index){
    struct node *p = head;
    struct node *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
    free(q);
    return head;
}
struct node * deleteAtLast(struct node * head){
    struct node *p = head;
    struct node *q = head->next;
    while(q->next !=NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = NULL;
    free(q);
    return head;
}
struct node * deleteByValue(struct node * head, int value){
    struct node *p = head;
    struct node *q = head->next;
    while(q->data!=value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}