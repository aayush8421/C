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

void preorder(struct node * root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node * root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void inorder(struct node * root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main(){
    /**   4
         / \
        1   6
       / \
      5   2
    */
    struct node * p = create(4);
    struct node * p1 = create(1);
    struct node * p2 = create(6);
    struct node * p3 = create(5);
    struct node * p4 = create(2);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    printf("Preorder traversal:\n");
    preorder(p);
    printf("\nPostorder traversal:\n");
    postorder(p);
    printf("\ninorder traversal:\n");
    inorder(p);

}