/* multiple parenthesis matching problem using stack */

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
match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    return 0;
}

int(parenthesismatch(char *expr))
{
    //create and initilize the stack
    struct stack *ptr;
    ptr->arr = (char *)malloc(ptr->size * sizeof(char));
    ptr->size = 20;
    ptr->top = -1;
    char char_pop;
    for (int i = 0; expr[i] != '\0'; i++)
    {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
        {
            push(ptr, expr[i]);
        }
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
        {
            if (isempty(ptr))
            {
                return 0;
            }
            char_pop = pop(ptr);
            // if not same use !
            if (!match(char_pop, expr[i]))
            {
                return 0;
            }
        }
    }
    if (isempty(ptr))
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
    
    char *exp = "[({8}*(9))";
    if (parenthesismatch(exp))
    {
        printf("parenthesis is matched\n");
    }
    else
    {
        printf("parenthesis is not matched\n");
    }
}