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
    
    
}