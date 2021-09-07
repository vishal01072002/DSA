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

void insertionsort(int *arr, int size)
{
    for (int i = 1; i <= size - 1; i++)
    //need size-1 pass
    //we have compare sort array "0" to next "0+1" index number
    {
        int num = arr[i]; //take num which have to insert in shorted array
        int j = i - 1;    //start compare from previous number (of shorted array) from int num or "i"
        while (j >= 0 && arr[j] > num)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = num; // coz j-- we put key in j+1
    }
}

void main()
{
    // only for example
   // -1   0    1   2   3   4   5
   //      12,| 54, 65, 07, 23, 09 --> i=1, key=54, j=0
   //      12,| 54, 65, 07, 23, 09 --> 1st pass done (i=1)!

   //      12, 54,| 65, 07, 23, 09 --> i=2, key=65, j=1
   //      12, 54,| 65, 07, 23, 09 --> 2nd pass done (i=2)!

   //      12, 54, 65,| 07, 23, 09 --> i=3, key=7, j=2
   //      12, 54, 65,| 65, 23, 09 --> i=3, key=7, j=1
   //      12, 54, 54,| 65, 23, 09 --> i=3, key=7, j=0
   //      12, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1
   //      07, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1--> 3rd pass done (i=3)!

   // Fast forwarding and 4th and 5th pass will give:
   //      07, 12, 54, 65,| 23, 09 --> i=4, key=23, j=3
   //      07, 12, 23, 54,| 65, 09 --> After the 4th pass

   //      07, 12, 23, 54, 65,| 09 --> i=5, key=09, j=4
   //      07, 09, 12, 23, 54, 65| --> After the 5th pass 

    int size = 6;
    int array[6] = {12, 4, 7, 9, 11, 33};
    printarray(array, size);
    insertionsort(array, size);
    printarray(array, size);
}