#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices

// Function to print the vertex cover
void printVertexCover(bool vertexCover[V])
{
    printf("Vertex Cover:\n");
    for (int i = 0; i < V; i++)
    {
        if (vertexCover[i])
        {
            printf("Vertex %d\n", i);
        }
    }
}

// Function to find a vertex cover using a greedy approach
void vertexCoverGreedy(int graph[V][V])
{
    bool vertexCover[V] = {false};     // Array to keep track of included vertices
    bool visitedEdges[V][V] = {false}; // Array to keep track of visited edges

    for (int u = 0; u < V; u++)
    {
        for (int v = u + 1; v < V; v++)
        {
            if (graph[u][v] && !visitedEdges[u][v])
            {
                // Include both vertices u and v in the vertex cover
                vertexCover[u] = true;
                vertexCover[v] = true;

                // Mark this edge as covered
                visitedEdges[u][v] = true;
                visitedEdges[v][u] = true;
            }
        }
    }

    printVertexCover(vertexCover);
}

int main()
{
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0}};

    vertexCoverGreedy(graph);

    return 0;
}
