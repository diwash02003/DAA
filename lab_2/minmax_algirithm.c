#include <stdio.h>

// Function to find the minimum and maximum in an array using divide and conquer
void findMinMax(int arr[], int left, int right, int *min, int *max)
{
    // If the array contains only one element
    if (left == right)
    {
        *min = *max = arr[left];
        return;
    }

    // If the array contains two elements
    if (right == left + 1)
    {
        if (arr[left] < arr[right])
        {
            *min = arr[left];
            *max = arr[right];
        }
        else
        {
            *min = arr[right];
            *max = arr[left];
        }
        return;
    }

    // Divide the array into two halves
    int mid = (left + right) / 2;
    int min1, max1, min2, max2;

    // Recursively find the min and max in both halves
    findMinMax(arr, left, mid, &min1, &max1);
    findMinMax(arr, mid + 1, right, &min2, &max2);

    // Combine the results from both halves
    *min = (min1 < min2) ? min1 : min2;
    *max = (max1 > max2) ? max1 : max2;
}

int main()
{
    int arr[] = {5, 7, 3, 4, 9, 12, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    findMinMax(arr, 0, n - 1, &min, &max);

    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    return 0;
}
