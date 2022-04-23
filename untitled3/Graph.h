#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices in the graph
#define N 6

// Data structure to store a graph object
struct Graph
{
    // An array of pointers to Node to represent an adjacency list
    struct Node* head[N];

    int order = sizeof(head) / sizeof(struct Node);

};

// Data structure to store adjacency list nodes of the graph
struct Node
{
    int dest;
    struct Node* next;
};

// Data structure to store a graph edge
struct Edge {
    int src, dest, cost;
};

// Function to create an adjacency list from specified edges
struct Graph* createGraph(struct Edge edges[], int n);

// Function to print adjacency list representation of a graph
void printGraph(struct Graph* graph);

