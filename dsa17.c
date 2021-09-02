/* queue implement and operation using array */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int f; //front value
    int r; //rear value
    int *arr;
};

int isfull(struct queue *q)
{
    if (q->r == ((q->size) - 1))
    {
        return 1;
    }
    else
        return 0;
}

int isempty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    else
        return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isfull(q))
    {
        printf("queue is full \n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    if (isempty(q))
    {
        printf("queue is empty \n");
    }
    else
    {
        q->f++;
        return q->arr[q->r];
    }
}

void main()
{
    struct queue q;
    q.size = 30;
    q.r = q.f = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    //enqueue(&q, 3);
    //enqueue(&q, 4);

    printf("queue deleted element is %d\n",dequeue(&q));
    printf("queue deleted element is %d\n",dequeue(&q));

    if (isempty(&q))
    {
        printf("queue is empty\n");
    }
    if (isfull(&q))
    {
        printf("queue is full\n");
    }
}