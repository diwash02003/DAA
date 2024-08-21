#include <stdio.h>
#include <stdlib.h>

// Define the structure for an item
typedef struct
{
    int value;
    int weight;
    double ratio;
} Item;

// Function to compare two items based on their value-to-weight ratio
int compare(const void *a, const void *b)
{
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    if (item1->ratio < item2->ratio)
        return 1;
    if (item1->ratio > item2->ratio)
        return -1;
    return 0;
}

// Function to implement the Fractional Knapsack problem
double fractionalKnapsack(int capacity, Item items[], int n)
{
    // Sort items based on their value-to-weight ratio in descending order
    qsort(items, n, sizeof(Item), compare);

    double totalValue = 0.0; // Initialize total value

    for (int i = 0; i < n; i++)
    {
        if (capacity == 0)
            break; // No more capacity in the knapsack

        // Take as much as possible from the current item
        int takeWeight = (items[i].weight <= capacity) ? items[i].weight : capacity;
        totalValue += takeWeight * items[i].ratio;
        capacity -= takeWeight;
    }

    return totalValue;
}

int main()
{
    int n; // Number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item *items = (Item *)malloc(n * sizeof(Item)); // Allocate memory for items

    // Input items values and weights
    printf("Enter the value and weight for each item:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (double)items[i].value / items[i].weight; // Calculate value-to-weight ratio
    }

    // Input the capacity of the knapsack
    int capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Call the fractionalKnapsack function
    double maxValue = fractionalKnapsack(capacity, items, n);

    // Print the maximum value that can be obtained
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    // Free allocated memory
    free(items);

    return 0;
}
