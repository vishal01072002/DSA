/* insert in binary search tree (BST) */

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

void inorder(struct node *roo)
{
    if (roo == NULL)
        return;
    else
    {
        inorder(roo->left);
        printf("%d,", roo->data);
        inorder(roo->right);
    }
}
struct node *inorderpre(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *delete (struct node *root, int key)
{
    struct node *inpre;
    // first reach that node

    //base condition for recursion
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    // base condition

    if (key < root->data)
    {
       root->left= delete (root->left, key);
    }
    else if (key > root->data)
    {
       root->right= delete (root->right, key);
    }
    else // key == root->data
    {
        inpre = inorderpre(root);
        root->data = inpre->data;
        root->left = delete (root->left, inpre->data);
    }
}

void main()
{
    struct node *T, *t1, *t2, *t3, *t4, *t5;
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
    delete (T, 5);
    printf("\n");
    inorder(T);
}
