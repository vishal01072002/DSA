/* circular linked list */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void list_traversal(struct node *head)
{
    int j = 0;   
    while (head != NULL)
    {
        j++;
        printf("element %d :%d\n", j, head->data);
        head = head->next;
    } 
        printf("reverse\n");
        j = 0;   
    while (head->next != NULL) { j++;  } 
    
    do
    {
         j--;
        printf("element %d :%d\n", j, head->data);
        head=head->prev;
    } while (head != NULL);
    
    
}

void main()
{
    system("cls");
    //int value = 33;
    //int indx = 2;
    struct node *head, *second, *third;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;
    head->prev = NULL;
    second->data = 11;
    second->next = third;
    head->prev = head;
    third->data = 30;
    third->next = NULL;
    head->prev = second;

    list_traversal(head);
    //head = insertatfirst(head, value);
    //list_traversal(head);
}