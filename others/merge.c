#include <stdio.h>
#include <stdlib.h>

// Function declarations
void printArray(int array[], int size);
void merge(int array[], int left, int mid, int right);
void mergeSort(int array[], int left, int right);

// Function to print the array
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

// Function to merge two subarrays of array[]
void merge(int array[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int leftArray[n1], rightArray[n2];

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (i = 0; i < n1; i++)
        leftArray[i] = array[left + i];
    for (j = 0; j < n2; j++)
        rightArray[j] = array[mid + 1 + j];

    // Merge the temporary arrays back into array[left..right]
    i = 0;    // Initial index of first subarray
    j = 0;    // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArray[], if there are any
    while (i < n1)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if there are any
    while (j < n2)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }

    // Print the array after merging
    printf("Merged array from index %d to %d: ", left, right);
    printArray(array + left, right - left + 1);
}

// Function to implement merge sort
void mergeSort(int array[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        printf("Dividing array from index %d to %d: ", left, mid);
        printArray(array + left, mid - left + 1);
        mergeSort(array, left, mid);

        printf("Dividing array from index %d to %d: ", mid + 1, right);
        printArray(array + mid + 1, right - mid);
        mergeSort(array, mid + 1, right);

        // Merge the sorted halves
        merge(array, left, mid, right);
    }
}

int main()
{
    int n;

    // Input the size of array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int array[n];

    // Input the elements of array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    // Perform merge sort
    printf("Initial array:\n");
    printArray(array, n);

    mergeSort(array, 0, n - 1);

    // Print the sorted array
    printf("Sorted array is: \n");
    printArray(array, n);

    return 0;
}
