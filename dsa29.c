/* search in binary search tree (BST) ----recursivly and iteratively---- */

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

struct node *search(struct node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (key == root->data)
    {
        return root;
    }

    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else //or else if (key > root->data)
    {
        return search(root->right, key);
    }
}

struct node *search_iterative(struct node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

void main()
{
    struct node *T, *t1, *t2, *t3, *t4, *t5, *n, *n1;
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
    n = search(T, 8);
    if (n != NULL)
    {
        printf("\n%d is found", n->data);
    }
    else
        printf("\nvalue is not found");

    // for iterative
    n1 = search(T, 1);
    if (n1 != NULL)
    {
        printf("\n%d is found", n1->data);
    }
    else
        printf("\nvalue is not found");
}
