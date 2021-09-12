/* quicksort algorithim */

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

int partition(int arr[], int low, int high)
{
    int value = arr[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (value >= arr[i]) // 3>=12 so stop
        {
            i++; //till we not get number which is greater than value
        }

        while (value < arr[j])
        {
            j--; //till we not get number which is less than value
        }

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    while (i < j); //j=0,i=1 or 0 also so conditition will false
    // now we get index where value or arr[low] should be placed
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    // then return that index j
    return j;
}

void quicksort(int arr[], int low, int high)
{

    // we do that till array is not empty or low < high
    if (low < high)
    {

        int partitonindex = partition(arr, low, high);
        printarray(arr, 9);
        // now we get left array and right array
        quicksort(arr, low, partitonindex - 1);
        //first we sort all left array then divide in array and then thats left array and so on.

        quicksort(arr, partitonindex + 1, high);
        //after solve left array we sort all right array then divide in array and then thats left array and so on.
    }
}

void main()
{
    int size = 9;
    int array[9] = {3, 12, 4, 7, 9, 1, 5, 11, 3};
    printarray(array, size);
    quicksort(array, 0, size - 1);
    printarray(array, size);
}