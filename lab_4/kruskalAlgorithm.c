#include <stdio.h>
#include <stdlib.h>

// Define the structure for an edge
typedef struct
{
    int src, dest, weight;
} Edge;

// Define the structure for a subset (used in Union-Find)
typedef struct
{
    int parent, rank;
} Subset;

// Function to find the root of the set containing 'i'
int find(Subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two subsets
void unionSets(Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Comparison function for sorting edges
int compare(const void *a, const void *b)
{
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

// Function to implement Kruskal's Algorithm
void kruskal(Edge edges[], int V, int E)
{
    Edge result[V]; // To store the resultant MST
    int e = 0;      // Count of edges in MST
    int i = 0;      // Initial index of sorted edges

    // Sort edges in increasing order of weight
    qsort(edges, E, sizeof(edges[0]), compare);

    // Allocate memory for creating V subsets
    Subset *subsets = (Subset *)malloc(V * sizeof(Subset));

    // Initialize subsets
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Process edges
    while (e < V - 1 && i < E)
    {
        // Take the smallest edge
        Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does not cause a cycle
        if (x != y)
        {
            result[e++] = next_edge;
            unionSets(subsets, x, y);
        }
    }

    // Print the MST
    printf("Edges in the Minimum Spanning Tree:\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);

    // Free allocated memory
    free(subsets);
}

// Main function
int main()
{
    // Number of vertices and edges
    int V = 4; // Number of vertices
    int E = 5; // Number of edges

    // Define edges of the graph
    Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}};

    // Call Kruskal's Algorithm
    kruskal(edges, V, E);

    return 0;
}
