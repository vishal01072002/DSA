/* queue implement and operation using linked list */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct nodequeue
{
    int data;
    struct nodequeue *next;
};

void list_traversal(struct nodequeue *ptr)
{
    int j = 0;
    while (ptr != NULL)
    {
        j++;
        printf("element %d :%d\n", j, ptr->data);
        ptr = ptr->next;
    }
}

struct nodequeue *f = NULL;
struct nodequeue *r = NULL;

void enqueue(int val)
{
    struct nodequeue *n = (struct nodequeue *)malloc(sizeof(struct nodequeue));
    if (n == NULL) //condition for is full
    {
        printf("queue is full \n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL) //condition for is empty
        {
            f = r = n;
        }
        else
        {
            r->next = n; //store addres of n in r next
            r = n;       // put r at rear position
        }

        printf("enqueue element is %d \n", val);
    }
}

int dequeue()
{
    int val = -1;
    struct nodequeue *ptr;
    ptr = f;
    if (f == NULL) //condition for empty
    {
        printf("queue is empty \n");
    }
    else
    {
        f = f->next;
        free(ptr);
        return val;
    }
}

void main()
{

    list_traversal(f);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    list_traversal(f);
    printf("queue deleted element is %d\n", dequeue());
    printf("queue deleted element is %d\n", dequeue());

    enqueue(5);
    list_traversal(f);
    //   printf("queue is empty\n");
}