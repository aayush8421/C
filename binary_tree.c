#include <stdio.h>
#include <stdlib.h>

typedef struct bnode
{
        char data;
        struct bnode *left;
        struct bnode *right;
} bnode;

void inorder(bnode *T)
{
        if (T != NULL)
        {
                inorder(T->left);
                printf("%c ", T->data);
                inorder(T->right);
        }
        return;
}

void preorder(bnode *T)
{
        if (T != NULL)
        {
                printf("%c ", T->data);
                preorder(T->left);
                preorder(T->right);
        }
        return;
}

void postorder(bnode *T)
{
        if (T != NULL)
        {
                postorder(T->left);
                postorder(T->right);
                printf("%c ", T->data);
        }
}

int main()
{
        bnode *T = (bnode *)malloc(sizeof(bnode)); /*pointer to the root node*/
        bnode *p;
        bnode *q;
        T = NULL;
        p = (bnode *)malloc(sizeof(bnode));
        p->data = 'A';
        p->left = NULL;
        p->right = NULL;
        T = p;
        q = T;

        p = (bnode *)malloc(sizeof(bnode));
        p->data = 'B';
        p->left = p->right = NULL;
        q->left = p;

        p = (bnode *)malloc(sizeof(bnode));
        p->data = 'C';
        p->left = p->right = NULL;
        q->right = p;
        q = T->left;

        p = (bnode *)malloc(sizeof(bnode));
        p->data = 'D';
        p->left = p->right = NULL;
        q->right = p;

        printf("\n The inorder traversal  is:\n");
        inorder(T);
        printf("\n The preorder traversal is:\n");
        preorder(T);
        printf("\n The postorder traversal is :\n");
        postorder(T);
}