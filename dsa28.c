/* to check binary tree is binary search (BST) or not */

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

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left)) // if left is not BST so not check for right
            return 0;
        if (prev != NULL && root->data <= prev->data) // if prev data is greater so it is not BST
            return 0;
        prev = root;               //
        return isBST(root->right); // if left is BST and prev value is small so check for right ,is BST or not
    }
    else
    {
        return 1; // 1 node tree is also a BST
    }
}

void main()
{
    struct node *T, *t1, *t2, *t3, *t4, *t5;
    int arr[5];
    T = createnode(5);
    t1 = createnode(3);
    t2 = createnode(6);
    t3 = createnode(1);
    t4 = createnode(4);
    T->left = t1;
    T->right = t2;
    t1->left = t3;
    t1->right = t4;
    t2->left = NULL;
    inorder(T);
    printf("\n%d", isBST(T));
}
