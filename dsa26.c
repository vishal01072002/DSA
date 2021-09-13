/* countsort sorting algorithim */

#include <stdio.h>
#include <conio.h>
#include <limits.h>
#include <stdlib.h>

void printarray(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

int maxvalue(int arr[], int n)
{
    int Max = INT_MIN;
    for (int i = 0; i <= n; i++)
    {
        if (Max < arr[i])
        {
            Max = arr[i];
        }
    }
    return Max;
}

void countsort(int *arr, int n)
{
    int i = 0, j;
    int max = maxvalue(arr, n);
    int *array = (int *)calloc(max + 1, sizeof(int)); // if array max is 6 so we need 7 space (for 0 zero)

    for (i = 0; i < max + 1; i++)
    {
        array[arr[i]]++;
    }

    i = 0, j = 0;
    while (j < n + 1)
    {
        if (array[j] != 0 && array[j] > 0) //or array[j]>0
        {
            arr[i] = j;
            array[j]--;
            i++;
        }
        else
        {
            j++;
        }
    }
}

void main()
{
    int size = 9;
    int array[9] = {3, 12, 4, 7, 9, 1, 5, 11, 3};
    printarray(array, size);
    countsort(array, size - 1);
    printarray(array, size);
}