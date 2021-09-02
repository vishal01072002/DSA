/* infix to postfix using stack */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int size;
    int top;
    char *arr;
};

int stacktop(struct stack *ptr)
{

    return ptr->arr[ptr->top];
}

int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    //or return ptr->top == -1;
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

void push(struct stack *ptr, char value)
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

char pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        printf("stack is empty\n");
        return -1;
    }
    else
    {
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
int isoperator(char ch)
{
    if (ch == '-' || ch == '/' || ch == '+' || ch == '*')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char *infixtopostfix(char *infix)
{
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->size = 20;
    ptr->top = -1;
    ptr->arr = (char *)malloc(ptr->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (!isoperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stacktop(ptr)))
            {
                push(ptr, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(ptr);
                j++;
            }
        }
    }
    while (!isempty(ptr))
    {
        postfix[j] = pop(ptr);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

void main()
{
    char *infix = "x-y/z-k*d";
    printf("postfix is %s", infixtopostfix(infix));
}