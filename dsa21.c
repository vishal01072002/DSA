/* bubble sorting algorithim */

#include <stdio.h>
#include <conio.h>

void printarray(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

void bubblesort(int *array, int n)
{
    for (int i = 0; i < n - 1; i++) //for number of pass
    {
        for (int j = 0; j < n - 1 - i; j++) //for comparision in each pass
        {
            if (array[j] > array[j + 1])
            {
                int temp;
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    printf("\n");
}
void bubblesort_adaptive(int *array, int n)
{
    int issorted = 0;
    for (int i = 0; i < n - 1; i++) //for number of pass
    {
        printf("pass is %d\n", i + 1);
        issorted = 1;
        for (int j = 0; j < n - 1 - i; j++) //for comparision in each pass
        {
            if (array[j] > array[j + 1])
            {
                int temp;
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                issorted = 0;
            }
        }
        if (issorted)
        {
            return;
        }
    }
    printf("\n");
}
void main()
{
    int n = 6;
    int arr[6] = {12, 4, 7, 9, 11, 33};
    printarray(arr, n);
     // bubblesort_adaptive(arr, n);
     // bubblesort(arr, n);
    printarray(arr, n);
}
