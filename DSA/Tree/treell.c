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
    // //root node
    // struct node *p;
    // p = (struct node*)malloc(sizeof(struct node));
    // p->data = 2;
    // p->left = NULL;
    // p->right = NULL;
    // //second node
    // struct node *p1;
    // p1 = (struct node*)malloc(sizeof(struct node));
    // p->data = 1;
    // p1->left = NULL;
    // p1->right = NULL;
    // //third node
    // struct node *p2;
    // p2 = (struct node*)malloc(sizeof(struct node));
    // p->data = 4;
    // p2->left = NULL;
    // p2->right = NULL;

    struct node * p = create(2);
    struct node * p1 = create(1);
    struct node * p2 = create(4);

    p->left = p1;
    p->right = p2;
}