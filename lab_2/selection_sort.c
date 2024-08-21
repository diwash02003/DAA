#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int array[], int size)
{
    int least, p;
    for (int i = 0; i < size - 1; i++)
    {
        least = array[i];
        p = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < least)
            {
                least = array[j];
                p = j;
            }
        }
        swap(&array[i], &array[p]);
    }
}

int main()
{
    int array[] = {7, 4, 10, 8, 3, 1};
    int size = sizeof(array) / sizeof(array[0]);

    selectionSort(array, size);
    printf("The sorted array is :");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
