#include <stdio.h>

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore the left half
        if (arr[mid] < target)
            left = mid + 1;

        // If target is smaller, ignore the right half
        else
            right = mid - 1;
    }

    // If the element is not present in array
    return -1;
}

int main()
{
    // Initialize the sorted array
    int arr[] = {10, 14, 19, 26, 31, 42, 44};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 31;

    // Perform binary search
    int result = binarySearch(arr, n, target);

    // Print the result
    if (result != -1)
    {
        printf("Element %d found at index %d\n", target, result);
    }
    else
    {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
