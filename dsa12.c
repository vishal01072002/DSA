/* stack peek operation in array */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int peek(struct stack *ptr, int pos)
{
    int ind = (ptr->top) - pos + 1;
    if (ind < 0)
    {
        printf("not valid position\n");
        return -1;
    }
    else
    {
        return ptr->arr[ind];
    }
}
int stacktop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int stackbottom(struct stack *ptr)
{
    return ptr->arr[0];
}
void main()
{
    system("cls");
    int val;
    struct stack *sptr = (struct stack *)malloc(sizeof(struct stack));
    sptr->size = 5;
    sptr->top = 2;
    sptr->arr = (int *)malloc(sptr->size * sizeof(int));
    sptr->arr[0] = 1;
    sptr->arr[1] = 2;
    sptr->arr[2] = 3;
    printf("enter the position\n");
    scanf("%d", &val);

    printf("value is %d\n", peek(sptr, val));
    printf("value top is %d\n", stacktop(sptr));
    printf("value bottom is %d\n", stackbottom(sptr));
}