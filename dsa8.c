/* circular linked list */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void list_traversal(struct node *head)
{
    struct node *ptr = head;
    int j = 0;
    //while (ptr != head)
    do
    {
        j++;
        printf("element %d :%d\n", j, ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}
struct node *insertatfirst(struct node *head, int value)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = value;
    struct node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

void main()
{
    system("cls");
    int value = 33;
    //int indx = 2;
    struct node *head, *second, *third;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;
    second->data = 11;
    second->next = third;
    third->data = 30;
    third->next = head;

    list_traversal(head);
    head = insertatfirst(head, value);
    //head = delatindex(head, indx);
    //head = delatend(head);
    //head = delatgive(head, value); //after second
    list_traversal(head);
}