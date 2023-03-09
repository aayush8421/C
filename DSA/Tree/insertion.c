#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node * create(int data){
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}
//iterative method
void insertIter(struct node * root,struct node * new){
    struct node * prev = NULL;
    while(root!=NULL){
        prev = root;
        if(new->data == root->data){
            return;
        }
        else if(new->data < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    if(new->data<prev->data){
        prev->left = new;
    }
    else{
        prev->right = new;
    }
}
//recursive method
void insertRecur(struct node * root,struct node * new){
    if(new->data<root->data){
        if(root->left == NULL){
            root->left = new;
        }
        else{
            insertRecur(root->left,new);
        }
    }
    else{
        if(root->right == NULL){
            root->right = new;
        }
        else{
            insertRecur(root->right,new);
        }
    }
}



int main(){
    /**   5
         / \
        3   6
       / \
      1   4
    */
    struct node * p = create(5);
    struct node * p1 = create(3);
    struct node * p2 = create(6);
    struct node * p3 = create(1);
    struct node * p4 = create(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    
    int key;
    printf("\nEnter the element to be inserted:\n");
    scanf("%d",&key);
    struct node * new = create(key);
    // insertIter(p,new);
    insertRecur(p,new);
    printf("%d",p->right->right->data);
}