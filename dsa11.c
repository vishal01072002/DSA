/* stack push , pop and others operation in array */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};

int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
        return 0;
}
int isfull(struct stack *ptr)
{
    if (ptr->top == (ptr->size) - 1)
    {
        return 1;
    }
    else
        return 0;
}

void push(struct stack *ptr, int value)
{
    if (isfull(ptr))
    {
        printf("stack is full\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
int pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        printf("stack is empty\n");
        return -1;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}
void main()
{
    system("cls");
    // this is from heap (daynamically requestd memeory)
    struct stack *sptr = (struct stack *)malloc(sizeof(struct stack));
    sptr->size = 5;
    sptr->top = -1;
    sptr->arr = (int *)malloc(sptr->size * sizeof(int));

    printf("isfull %d\n", isfull(sptr));
    printf("isempty%d\n", isempty(sptr));
    push(sptr, 41);
    push(sptr, 42);
    push(sptr, 43);
    push(sptr, 44);
    push(sptr, 45);
    push(sptr, 46);
    push(sptr, 47);
    printf("isfull %d\n", isfull(sptr));
    printf("isempty%d\n", isempty(sptr));
    printf("popped%d\n", pop(sptr));
}