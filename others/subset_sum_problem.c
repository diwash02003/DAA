#include <stdio.h>
#include <stdbool.h>

// Function to print a subset
void printSubset(int subset[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

// Recursive function to find all subsets with the given sum
void findSubsets(int arr[], int n, int subset[], int subsetSize, int sum)
{
    // Base Case: If the sum is zero, print the current subset
    if (sum == 0)
    {
        printSubset(subset, subsetSize);
        return;
    }

    // If no elements are left or the sum becomes negative, return
    if (n == 0 || sum < 0)
    {
        return;
    }

    // Include the last element in the subset and recurse
    subset[subsetSize] = arr[n - 1];
    findSubsets(arr, n - 1, subset, subsetSize + 1, sum - arr[n - 1]);

    // Exclude the last element from the subset and recurse
    findSubsets(arr, n - 1, subset, subsetSize, sum);
}

int main()
{
    int arr[] = {1, 3, 4, 5};
    int sum = 10;
    int totalsum = 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        totalsum = totalsum + arr[i];
    }
    printf("Total sum of array is: %d\n", totalsum);
    int subset[n]; // Array to store the current subset

    if (totalsum >= sum)
    {
        printf("Subsets with sum %d are:\n", sum);
        findSubsets(arr, n, subset, 0, sum);
    }
    else
    {
        printf("sum should be less than or equal to array sum\n");
    }

    return 0;
}
