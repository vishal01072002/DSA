/*  oprations on array  */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

//this is triversal
void display(int arr[], int len)
{
   for (int i = 0; i < len; i++)
   {
      printf("%d  ", arr[i]);
   }
   printf("\n");
}

int indx_insertion(int arr[], int used_siz, int element, int capacity, int index)
{
   if (used_siz >= capacity)
   {
      return -1;
   }
   else
   {
      for (int i = used_siz; i > index; i--)
      {
         arr[i] = arr[i - 1];
      }
      arr[index] = element;
      return 1;
   }
}
// 1. array trivesal
// 2. array insertion
void main()
{
   system("cls");
   int arr[20] = {2, 4, 8, 3, 9, 5};
   int used_siz = 6, capacity = 20, element = 30, index = 2;
   display(arr, used_siz);
   indx_insertion(arr, used_siz, element, capacity, index);
   //because we insert an element
   used_siz += 1;
   if (indx_insertion == -1)
   {
      printf("element is not inserted");
   }
   else
   {
      printf("element is inserted\n");
      display(arr, used_siz);
   }
}