#include<stdio.h>
#include<stdlib.h>

typedef struct bstnode{
    int data;
    struct bstnode * left;
    struct bstnode * right;
}bstnode;

bstnode * create(int data){
    bstnode * t = (bstnode *)malloc(sizeof(bstnode));
    t->data = data;
    t->left = NULL;
    t->right = NULL;

    return t;
}

int search (bstnode * root,int k){
    if(root==NULL)
    return 0;
    if (root->data==k)
    return 1;
    if(root->data<k)
    return search(root->right,k);
    else
    return search(root->left,k);
}

void insertion(bstnode * root,bstnode * newnode){
    if(root->data>newnode->data){
        if(root->left == NULL)
        root->left = newnode;
        else
        insertion(root->left,newnode);
    }
    else{
        if(root->right == NULL)
        root->right = newnode;
        else
        insertion(root->right,newnode);
    }
}

void inorder(bstnode * root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d  ",root->data);
        inorder(root->right);
    }
    return;
}

void preorder(bstnode *root){
    if (root != NULL){
        printf("%d  ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
    return;
}

void postorder(bstnode *root){
    if (root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d  ", root->data);
    }
}

int main(){
    // int data;
    // printf("Enter the root element of BST:\n");
    // scanf("%d",&data);
    // bstnode * root = create(data);
    // int n;
    // printf("Do u want to enter more elements (1:yes/0:no):\n");
    // scanf("%d",&n);
    // while(n==1){
    //     printf("Enter the element:\n");
    //     scanf("%d",&data);
    //     bstnode * t = create(data);
    //     insertion(root,t);
    //     printf("Do u want to enter more elements (1:yes/0:no):\n");
    //     scanf("%d",&n);
    // }
    
    // inorder(root);
    // int key;
    // printf("\nEnter the element to be searched:\n");
    // scanf("%d",&key);
    // if(search(root,key)==1)
    // printf("Element present\n");
    // else
    // printf("Element absent\n");
    bstnode * root;
    while(1){
        int choice;
        printf("\nEnter the choice\n");        
        printf("1.Creation\n");        
        printf("2.Insertion\n");        
        printf("3.Inorder Traversal\n");        
        printf("4.Preorder Traversal\n");        
        printf("5.Postorder traversal\n");              
        printf("6.Exit\n");
        scanf("%d",&choice);
        char data;
        switch(choice){
            case 1:
            printf("Enter the value of the root node\n");
            scanf("%d",&data);
            root = create(data);
            printf("Bnary Tree with the root node %d created\n",data);
            break;
            case 2:
            printf("Enter the value to be inserted:\n");
            scanf("%d",&data);
            bstnode * n = create(data);
            insertion(root,n);
            printf("%d inserted into the Binary Tree\n",data);
            break;
            case 3:
            printf("The Inorder traversal:\n");
            inorder(root);
            break;
            case 4:
            printf("The Preorder traversal:\n");
            preorder(root);
            break;
            case 5:
            printf("The Postorder traversal:\n");
            postorder(root);
            break;
            // case 6:
            // printf("Enter the value to searched:\n");
            // scanf("%d",&data);
            // if(search(root,data)==1)
            // printf("Element present\n");
            // else
            // printf("Element absent\n");
            // break;
            case 6:
            exit(1);
            break;
            default:
            printf("wrong choice!!!!Try again\n");
        }
    }
}