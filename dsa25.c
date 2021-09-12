/* mergesort sorting algorithim */

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

void merge(int arr[], int mid, int low, int high)
{
    int ary[high + 1];
    int i = low, j = mid+1, k = low;
    while (i <= mid && j <= high)
    {
        // which is small it will be insert in new array
        if (arr[i] < arr[j])  
        {
            ary[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            ary[k] = arr[j];
            j++;
            k++;
        }
    }
    // if any array is end before 2nd one so put that all value in new array
    while (i <= mid)
    {
        ary[k] = arr[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        ary[k] = arr[j];
        k++;
        j++;
    }

// now copy new array in previous array 
    for (int x = low; x < high + 1; x++)
    {
        arr[x] = ary[x];
    }
}
void mergesort(int arr[], int low, int high) //,int m,int n
{
    int mid = (high + low) / 2; // or (high/2)+1;
    if (low < high)
    {
        mergesort(arr, low, mid);  //it will divide left array till one element array
        mergesort(arr, mid + 1, high);
        merge(arr, mid, low, high);  // after divide  array in one element we merge all element
    }
}

void main()
{
    int size = 9;
    int array[9] = {3, 12, 4, 7, 9, 1, 5, 11, 3};
    printarray(array, size);
    mergesort(array, 0, size - 1);
    printarray(array, size);
}