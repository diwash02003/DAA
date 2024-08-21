#include <stdio.h>
#include <stdlib.h> // Include for rand()

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int p, int r)
{
    // Ensure p and r are within valid bounds
    if (p < 0 || r < p)
        return p;

    int pivotIndex = p + rand() % (r - p + 1);
    int pivot = arr[pivotIndex];
    int i = p - 1;
    int j;

    swap(&arr[pivotIndex], &arr[r]); // Move pivot to the end
    for (j = p; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]); // Place pivot in the correct position
    return i + 1;               // Return the index of the pivot
}

void quick_sort(int arr[], int p, int q)
{
    int j;
    if (p < q)
    {
        j = partition(arr, p, q);
        if (j >= 0)
        {
            quick_sort(arr, p, j - 1);
            quick_sort(arr, j + 1, q);
        }
    }
}

int main()
{
    int i, n;
    int arr[] = {12, 465, 43, 63, 64, 7, 100, 1};
    n = sizeof(arr) / sizeof(arr[0]);


    quick_sort(arr, 0, n - 1);

    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    return 0;
}
