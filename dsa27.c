/* binary tree implimentation and traversal */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *n;
    n = malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preorder(struct node *root)
{
    if (root == NULL)
        return;
    else
    {
        printf("%d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root == NULL)
        return;
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->data);
    }
}
void inorder(struct node *root)
{
    if (root == NULL)
        return;
    else
    {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}

void main()
{
    struct node *T, *t1, *t2, *t3, *t4, *t5;
    T = createnode(3);
    t1 = createnode(4);
    t2 = createnode(6);
    t3 = createnode(8);
    t4 = createnode(5);
    t5 = createnode(7);
    T->left = t1;
    T->right = t2;
    t1->left = t3;
    t1->right = t4;
    t2->left = NULL;
    t2->right = t5;
    preorder(T);
     printf("\n");
    postorder(T);
     printf("\n");
    inorder(T);
}
