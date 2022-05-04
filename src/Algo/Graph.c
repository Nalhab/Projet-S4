#include "Graph.h"
#define INF 999

struct Graph* createGraph(int n, struct list* List, int nbEdges)
{
    	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->adjLists = calloc(n,sizeof(int*));
	for(int i = 0; i < n; i++)
	{
		graph->adjLists[i] = calloc(n,sizeof(int));
	}
	graph->head = calloc(n, sizeof(struct Node));
    	
	// initialize head pointer for all vertices
	for (int i = 0; i < n; i++) 
	{
		graph->head[i] = NULL;
   	}
	
	// add edges to the directed graph one by one
    	for (int i = 0; i < nbEdges; i++)
    	{
		int src = List->data.src;
		int dest = List->data.dest;
	
        	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        	newNode->dest = dest;
		
		
		graph->adjLists[src][dest] = List->data.cost;	
        	
		newNode->next = graph->head[src];
        	graph->head[src] = newNode;
		List = List->next;
    	}
	return graph;
}

void printGraph(struct Graph* graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        struct Node* ptr = graph->head[i];
        while (ptr != NULL)
        {
            printf("(%d -> %d)\t", i, ptr->dest);
            ptr = ptr->next;
        }

        printf("\n");
    }
}


// Directed graph implementation in C
/*int main(void)
{
    // input array containing edges of the graph (as per the above diagram)
    // (x, y) pair in the array represents an edge from x to y
    struct Edge edges[] =
            {
                    {0, 1, 1}, {1, 2, 2}, {2, 3, 3}, {3, 4, 4}, {4, 0, 5}
            };
    struct list* List = malloc(sizeof(struct list));
        List->data = edges[0];
    	for(int i = 1; i < 5; i++)
        {
                struct list* nList = malloc(sizeof(struct list));
                nList->data = edges[i];
                list_push_front(List, nList);
        }
    
	// calculate the total number of edges
    int n = sizeof(edges)/sizeof(edges[0]);
    
	// construct a graph from the given edges
    struct Graph *graph = createGraph(n,List);

    for(int i = 0; i < n; i++)
    {
	    for(int j = 0; j < n; j++)
	    {
		    printf("%d ", graph->adjLists[i][j]);
	    }
	    printf("\n");
    }
    // Function to print adjacency list representation of a graph
   printGraph(graph);	
    return 0;
}*/

