#include "Graph.h"

struct Graph* createGraph(struct Edge edges[], int n)
{
    	// allocate storage for the graph data structure
    	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

    	// initialize head pointer for all vertices
	for (int i = 0; i < N; i++) 
	{
		graph->head[i] = NULL;
   	}
	
	/*graph->adjLists = calloc(N, sizeof(int));
        for (int i = 0; i < N; i++)
        {
                graph->adjLists[i] = calloc(N, sizeof(int));
        }
	for(int i = 0; i < N; i++)
        {
                printf("{ ");
                for(int j = 0; j < N; j++)
                {
                        printf("%i, ",graph->adjLists[i][j]);
                }
                printf("},\n");
        }
	printf("\n");*/
	// add edges to the directed graph one by one
    	for (int i = 0; i < n; i++)
    	{
		// get the source and destination vertex
		int src = edges[i].src;
		int dest = edges[i].dest;
	
		// allocate a new node of adjacency list from src to dest
        	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        	newNode->dest = dest;
		//printf("%d, %d \n",i ,dest);
		graph->adjLists[src][dest] = edges[i].cost;	
		// point new node to the current head
        	newNode->next = graph->head[src];
        	// point head pointer to the new node
        	graph->head[src] = newNode;
    	}
	for(int i = 0; i < N; i++)
        {
                printf("{ ");
                for(int j = 0; j < N; j++)
                {
                        printf("%i, ",graph->adjLists[i][j]);
                }
                printf("},\n");
        }	
	return graph;
}

void printGraph(struct Graph* graph)
{
    for (int i = 0; i < N; i++)
    {
        // print current vertex and all its neighbors
        struct Node* ptr = graph->head[i];
        while (ptr != NULL)
        {
            printf("(%d -> %d)\t", i, ptr->dest);
            ptr = ptr->next;
        }

        printf("\n");
    }
}


/*
// Directed graph implementation in C
int main(void)
{
    // input array containing edges of the graph (as per the above diagram)
    // (x, y) pair in the array represents an edge from x to y
    struct Edge edges[] =
            {
                    {0, 1, 1}, {1, 2, 2}, {2, 3, 3}, {3, 4, 4}, {4, 0, 5}
            };

    // calculate the total number of edges
    int n = sizeof(edges)/sizeof(edges[0]);
    
	// construct a graph from the given edges
    struct Graph *graph = createGraph(edges, n);

    // Function to print adjacency list representation of a graph
    //printGraph(graph);
	
	for(int i = 0; i < N; i++)
	{
		printf("{ ");
		for(int j = 0; j < N; j++)
		{
			printf("%i, ",graph->adjLists[i][j]);
		}
		printf("},\n");
	}

    return 0;
}
*/

