#include <stdio.h>

int main()
{
    int array[] = {25, 57, 48, 37, 12, 92, 86, 33}, j;
    int size = sizeof(array) / sizeof(array[1]);
    printf("size of array is : %d \n", size);
    for (int i = 1; i < size; i++)
    {
        int temp = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = temp;
    }
    printf("the sorted array is :");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}