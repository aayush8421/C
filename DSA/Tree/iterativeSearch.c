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

// struct node * search(struct node * root,int key){
//     if(root == NULL)
//     return NULL;
//     if(key == root->data)
//     return root;
//     else if(key<root->data)
//     return search(root->left,key);
//     else
//     return search(root->right,key);
// }

struct node * searchiter(struct node * root,int key){
    while(root!=NULL){
        if(key == root->data)
        return root;
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
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
    printf("\nEnter the element:\n");
    scanf("%d",&key);
    struct node * n = searchiter(p,key);
    if(n!=NULL){
        printf("Found: %d",n->data);
    }
    else{
        printf("Not Found");
    }


}