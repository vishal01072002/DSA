/*  implimentation of ADT (abstract data type) array */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct myarray
{
    int maxsize;
    int usesize;
    int *ptr;
};

void create(struct myarray *a, int msize, int usize)
{
    (*a).maxsize = msize;
    a->usesize = usize;
    /* (*a).ptr */
    a->ptr = (int *)malloc(msize * sizeof(int));
}

void setval(struct myarray *a)
{
    for (int i = 0; i < a->usesize; i++)
    {
        printf("enter %d element ", i + 1);
        scanf("%d", &(a->ptr)[i]);
    }
}

void show(struct myarray *a)
{
    for (int i = 0; i < a->usesize; i++)
    {
        printf("%d \n", (a->ptr)[i]);
    }
}

void main()
{
    system("cls");
    struct myarray marks;
    create(&marks, 10, 2);
    printf("insert value\n");
    setval(&marks);
    printf("show value\n");
    show(&marks);
}