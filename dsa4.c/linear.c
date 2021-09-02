/*  searching 1. linear 2.binary  */
// linear is aplicable for shorted and unshorted array comlexiy O(n)
// binary is aplicable for shorted array only comlexity O(logn)
#include <stdio.h>
#include <conio.h>
int linear_search(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (element == arr[i])
        {
            return i;
        }
    }
    return -1;
}
void main()
{
    system("cls");
    int arr[] = {3, 7, 22, 9, 5, 90};
    //   OR SIZE = SIZEOF(ARR)/SIZEOF(INT)

    int size = 6, element = 0;
    printf("enter element for find in array \n");
    scanf("%d", &element);
    int indx = linear_search(arr, size, element);
    if (indx >= 0)
    {
        printf("element found at index %d\n", indx);
    }
    else
    {
        printf("element not found\n");
    }
}