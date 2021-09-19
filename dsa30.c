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

void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root; //coz we need prev adress to store left and right element
        if (root->data == key)
        {
            printf("no space for %d\n", key);
            return; //coz same element can not insert in BST
        }
        // else update the value of root
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    // after loop we have node where element will insert or ----after the prev node (prev node is leaf node )----
    struct node *new = createnode(key);
    if (key < prev->data)
    {
        // printf("left prev new%d\n", prev->data);
        prev->left = new;
        // printf("left new%d\n", new->data);
    }
    else
    {
        // printf("right prev new%d\n", prev->data);
        prev->right = new;
        // printf("right new%d\n", new->data);
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
    insert(T, 2);
    insert(T, 5);
    insert(T, 9);
    insert(T, 7);
    //   printf("%d\n", T->data);
    // printf("\n%d\n", T->left->data);
    //  printf("\n%d\n", T->left->left->right->data);
    inorder(T);
}
