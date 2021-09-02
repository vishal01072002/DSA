/* circukar queue implement and operation using array */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct circularqueue
{
    int size;
    int f; //front value
    int r; //rear value
    int *arr;
};

int isfull(struct circularqueue *q)
{
    if ((q->r+1)%q->size == q->f)
    {
        return 1;
    }
    else
        return 0;
}

int isempty(struct circularqueue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    else
        return 0;
}

void enqueue(struct circularqueue *q, int val)
{
    if (isfull(q))
    {
        printf("queue is full \n");
    }
    else
    {
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
        printf("enqueue element is %d \n",val);
    }
}

int dequeue(struct circularqueue *q)
{
    if (isempty(q))
    {
        printf("queue is empty \n");
    }
    else
    {
        q->f=(q->f+1)%q->size;
        return q->arr[q->r];
    }
}

void main()
{
    struct circularqueue q;
    q.size = 3;
    q.r = q.f = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 4);

    printf("queue deleted element is %d\n",dequeue(&q));
    printf("queue deleted element is %d\n",dequeue(&q));

    enqueue(&q, 5);
    if (isempty(&q))
    {
        printf("queue is empty\n");
    }
    if (isfull(&q))
    {
        printf("queue is full\n");
    }
}