/* selection sorting algorithim */

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

void selectionsort(int *arr, int n)
{
    int minvalueindx = 0;
    for (int i = 0; i < n; i++)
    {
        minvalueindx = i;
        for (int j = i + 1; j < n; j++) //coz we start compare from next
        {
            if (arr[j] < arr[minvalueindx]) //if we get small so update that minvalindex
            {
                minvalueindx = j;
            }
        } //end of this loop we get samllest value of array
        //now we swap that value "minvalindx" and "first element" orrr "i"
        int temp;
        temp = arr[i];
        arr[i] = arr[minvalueindx];
        arr[minvalueindx] = temp;
    }
}
void main()
{
     int size = 6;
    int array[6] = {12, 4, 7, 9, 11, 33};
    printarray(array, size);
    selectionsort(array,size);
    printarray(array,size);
}