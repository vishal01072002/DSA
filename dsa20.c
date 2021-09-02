/* double ended queue (DEqueue) implement and operation using array */

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
    if ((q->r == -1) && (q->f == -1))
    {
        return 1;
    }
    else
        return 0;
}

void enqueueR(struct queue *q, int val)
{
    if (isfull(q))
    {
        printf("queue is full \n");
    }
    else
    {
        if ((q->f == -1) && (q->r == -1))
            q->f = 0;
        q->r++;
        q->arr[q->r] = val;
        printf("queueR insert element is %d\n", q->arr[q->r]);
    }
}

void enqueueF(struct queue *q, int valu)
{
    if (q->f == 0 && q->r == q->size - 1 || (q->f == q->r + 1))
    {
        printf("queue is full \n");
    }
    else if ((q->f == -1) && (q->r == -1)) // for add first element
    {
        q->f = q->r = 0;
        q->arr[q->f] = valu;
        //  printf(" no space in queue front\n");
    }

    else
    {
        q->arr[q->f] = valu;
        printf("queueF insert element is %d\n", q->arr[q->f]);
        q->f--;
    }
}

int dequeueF(struct queue *q)
{
    if (isempty(q))
    {
        printf("queue is empty \n");
    }
    else
    {
        q->f++;
        return q->arr[q->f];
    }
}

int dequeueR(struct queue *q)
{
    if (isempty(q))
    {
        printf("queue is empty \n");
    }
    else
    {
        if (q->r == -1)
        {
            printf(" no element in queue to delete at rear\n");
        }
        else
        {
            q->r = q->r - 1;
            return q->arr[q->r + 1];
        }
    }
}

void main()
{
    struct queue q;
    q.size = 30;
    q.r = q.f = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueueR(&q, 3);
    enqueueR(&q, 4);
    enqueueF(&q, 5);
    enqueueR(&q, 6);
    enqueueR(&q, 7);
    // enqueueF(&q, 4);

    printf("queueF deleted element is %d\n", dequeueR(&q));
    printf("queueF deleted element is %d\n", dequeueR(&q));
    printf("queueF deleted element is %d\n", dequeueR(&q));
    printf("queueF deleted element is %d\n", dequeueR(&q));
    // printf("queueF deleted element is %d\n", deqeueF(&q));
    // printf("queueF deleted element is %d\n", dequeueF(&q));
}