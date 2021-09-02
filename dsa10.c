/* stack implement in array */

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
    {
        return 0;
    }
}
int isfull(struct stack *ptr)
{
    if (ptr->top == (ptr->size) - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void main()
{
    system("cls");
    // using pointer
    // this is from stack
    struct stack *s; //pointer s
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    /*
       struct stack first;
    first.size = 20;
    first.top = -1; // nothing in stack
    first.arr = (int *)malloc(first.size * sizeof(int));
    */

    //manully put the value
    s->arr[0] = 4;
    s->top++;

    if (isempty(s))
    {
        printf("the stack is empty\n");
    }
    else
    {
        printf("the stack is not empty\n");
    }
}