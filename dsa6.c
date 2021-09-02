/*  insertion in linked list  */
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

/*struct node *insrtatfirst(struct node *head, int datas)
{
   struct node *ptr = (struct node *)malloc(sizeof(struct node));
   ptr->next = head;
   ptr->data = datas;
   return ptr;
}*/

/*
struct node *insrtatindex(struct node *head, int datas, int indx)
{
   struct node *ptr = (struct node *)malloc(sizeof(struct node));
   struct node *p = head;
   int i = 0;
   while (i != indx - 1)
   {

      p = p->next;
      i++;
   }

   ptr->next = p->next; //store addres of the elelment which index we want 2 p is 1
   p->next = ptr;       //store ptr address in 1
   ptr->data = datas;
   return head;
}*/
/*
struct node *insrtatend(struct node *head, int datas)
{
   struct node *ptr = (struct node *)malloc(sizeof(struct node));
   ptr->data = datas;
   struct node *p = head;
   int i = 0;
   while (p->next != NULL)
   {
      p = p->next;
      i++;
   }

   p->next = ptr; //store ptr address at the place of null
   ptr->next = NULL;
   return head;
}  */
struct node *insrtataftergive
(struct node *head, struct node *given_node, int datas)
{
   struct node *ptr = (struct node *)malloc(sizeof(struct node));
   ptr->next = given_node->next; //next element of given stored in ptr pointed
   given_node->next = ptr;       //given point to ptr
   ptr->data = datas;
   return head;
}

void main()
{
   system("cls");
   //printf("");
   //scanf("",&);
   int value = 34;
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
   third->next = NULL;

   list_traversal(head);
   //head = insrtatfirst(head, value);
   //head = insrtatindex(head, value, indx);
   //head = insrtatend(head, value);
   head = insrtataftergive(head, second, value);//after second
   list_traversal(head);
}