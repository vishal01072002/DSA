/*  searching 1. linear 2.binary  */
// linear is aplicable for shorted and unshorted array comlexiy O(n)
// binary is aplicable for shorted array only comlexity O(logn)
#include <stdio.h>
#include <conio.h>
int binary_search(int arr[], int size, int element)
{
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
void main()
{
    system("cls");
    int arr[] = {3, 5, 7, 9, 17, 90};
    //   OR SIZE = SIZEOF(ARR)/SIZEOF(INT)

    int size = 6, element;
    printf("enter element for find in array \n");
    scanf("%d", &element);
    int indx = binary_search(arr, size, element);
    if (indx >= 0)
    {
        printf("element %d found at index %d\n", element, indx);
    }
    else
    {
        printf("element not found\n");
    }
}