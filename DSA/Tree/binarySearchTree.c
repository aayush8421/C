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

void inorder(struct node * root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int isBST(struct node * root){
    static struct node * prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data<=prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
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
    // printf("Preorder traversal:\n");
    // preorder(p);
    // printf("\nPostorder traversal:\n");
    // postorder(p);
    printf("Inorder traversal:\n");
    inorder(p);
    printf("\n%d",isBST(p));


}