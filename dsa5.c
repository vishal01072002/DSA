/*  linked list creation and traversal  */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *next;
};

// complexity is o(n)
void list_traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("element :%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void main()
{
    system("cls");

    // its allocated in heap
    struct node *head, *second, *third;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    //link head and second
    head->data = 7;
    head->next = second;
    //link  second and third
    second->data = 11;
    second->next = third;
    //link head and null  ..or.. terminate the list
    third->data = 30;
    third->next = NULL;

    list_traversal(head);
}