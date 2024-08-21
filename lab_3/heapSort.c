#include <stdio.h>

// Function to swap two elements using a temporary variable
void swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

// Function to heapify a subtree rooted with node i which is an index in array[]
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

// Function to perform heap sort
void heapSort(int array[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        swap(array, 0, i);

        // call max heapify on the reduced heap
        heapify(array, i, 0);
    }
}
// function to print array
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
    printf("Sorted array is: \n");

    printArray(array, n);

    return 0;
}
