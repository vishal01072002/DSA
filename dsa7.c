/*  deletion in linked list  */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void list_traversal(struct node *ptr)
{
    int j = 0;
    while (ptr != NULL)
    {
        j++;
        printf("element %d :%d\n", j, ptr->data);
        ptr = ptr->next;
    }
}
/*
struct node *delatfirst(struct node *head)
{
   struct node *ptr = (struct node *)malloc(sizeof(struct node));
   ptr = head;
   head=ptr->next;
   free(ptr);
   return head;
}*/

/*
struct node *delatindex(struct node *head,int indx)
{
   struct node *p = head;
   struct node *q = p->next;
   int i = 0;
   while (i != indx - 1)
   {
      p = p->next;
      q = q->next;
      i++;
   }
  p->next=q->next;
   free(q);
   return head;
}*/
/*
struct node *delatend(struct node *head)
{
   struct node *p = head;
   struct node *q = p->next;
   int i = 0;
   while (q->next != NULL)
   {
      p = p->next;
      q = q->next;
      i++;
   }
   p->next = NULL;
   free(q);
   return head;
}*/

struct node *delatgive(struct node *head, int value)
{
    struct node *p = head;
    struct node *q = p->next;
    while (q->next != NULL && q->data != value)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    else
    {
        printf("\nyour given value is not valid");
    }    
    return head;
}

void main()
{
    system("cls");
    int value = 11;
    int indx = 2;
    struct node *head, *second, *third;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;
    second->data = 11;
    second->next = third;
    third->data = 30;
    third->next = NULL;

    list_traversal(head);
    //head = delatfirst(head);
    //head = delatindex(head, indx);
    //head = delatend(head);
    head = delatgive(head, value); //after second
    list_traversal(head);
}