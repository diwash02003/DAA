#include <stdio.h>
#include <stdlib.h>

// Function declarations
void swap(int array[], int i, int j);
void heapify(int array[], int n, int i);
void heapSort(int array[], int n);
void printArray(int array[], int n);

void swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void heapify(int array[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && array[left] > array[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && array[right] > array[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        swap(array, i, largest);

        // Recursively heapify the affected sub-tree
        heapify(array, n, largest);
    }
}

void heapSort(int array[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    printf("Max Heap:\n");
    printArray(array, n); // Print the max heap

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        swap(array, 0, i);

        // call max heapify on the reduced heap
        heapify(array, i, 0);

        printf("Heap after removing %d elements:\n", n - i);
        printArray(array, i); // Print the heap after each extraction
    }
}

void printArray(int array[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int array[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    heapSort(array, n);
    printf("Sorted array is:\n");

    printArray(array, n);

    return 0;
}
