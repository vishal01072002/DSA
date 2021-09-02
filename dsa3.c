/*  deletion in array  */
#include <stdio.h>
#include <conio.h>

void display(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void indx_deletion(int arr[], int used_siz, int index)
{

    for (int i = index; i < used_siz; i++)
    {
        arr[i] = arr[i + 1];
    }
}
// 1. array trivesal
// 2. array insertion
void main()
{
    system("cls");
    int arr[20] = {2, 4, 8, 3, 9, 5};
    int used_siz = 6, index = 3;
    display(arr, used_siz);
    indx_deletion(arr, used_siz, index);
    //because we delete an element
    used_siz -= 1;
    printf("element is deleted\n");
    display(arr, used_siz);
}