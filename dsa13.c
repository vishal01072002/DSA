/* stack operation using linked list */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
/*
when top is global variable

int pop(struct node *Top)
{
    if (isempty(Top))
    {
        printf("stack is empty\n");
    }
    else
    {
        int a = Top->data;
        struct node *n =Top;
        a = n->data;
        top = Top->next;
        free(n);
        return a;
    }
}

*/
void list_traversal(struct node *ptr)
{
    int j = 0;
    while (ptr != NULL)
    {
        j++;
        printf("element %d :%d \n", j, ptr->data);
        ptr = ptr->next;
    }
}

int isfull(struct node *ptr)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        return 1;
    }
    else
        return 0;
}

int isempty(struct node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    else
        return 0;
}
struct node *push(struct node *top, int a)
{
    if (isfull(top))
    {
        printf("stack is over flow\n");
    }
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = a;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct node *(*top))
{
    if (isempty(*top))
    {
        printf("stack is empty\n");
    }
    else
    {
        int a = (*top)->data;
        struct node *n = *top;
        a = n->data;
        *top = (*top)->next;
        free(n);
        return a;
    }
}

int peek(struct node *ptr, int pos)
{
    for (int i = 0; i < pos - 1 && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}
int bottom(struct node *ptr)
{
    for (int i = 0; i < ptr->next != NULL; i++)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}

void main()
{
    int element, position = 2;
    system("cls");
    struct node *top = NULL;
    top = push(top, 30);
    top = push(top, 60);
    top = push(top, 90);

    /*when top is global variable
    element = pop(top);
    element = pop(&top);
    printf("pop element is %d\n", element);
    */
    //element = pop(&top);
    //printf("pop element is %d\n", element);
    list_traversal(top);
    //element = peek(top, position);
    //printf("element is %d\n", element);
    element = bottom(top);
    printf(" bottom element is %d\n", element);
}