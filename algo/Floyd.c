#include "Graph.h"
#include <stdio.h>
#define len 5  //Number of vertice 
#define INF 999

void printMatrix(int matrix[][len]);

void floydWarshall(int graph[][len]) 
{
	int res[len][len];
       	int i, j, k;
	
	for (i = 0; i < len; i++)
		for (j = 0; j < len; j++)
			res[i][j] = graph[i][j];

	for (k = 0; k < len; k++) 
	{
		for (i = 0; i < len; i++) 
		{
			for (j = 0; j < len; j++) 
			{
				if (res[i][k] + res[k][j] < res[i][j])
					res[i][j] = res[i][k] + res[k][j];
			}
    		}
  	}
	printMatrix(res);
}

void printMatrix(int matrix[][len])
{
	for (int i = 0; i < len; i++) 
	{
		for (int j = 0; j < len; j++)
		{
			if (matrix[i][j] == INF) 
				printf("%4s", "INF");
			else
				printf("%4d", matrix[i][j]);
    		}
    		printf("\n");
  	}
}

int main() {
	//All edges of the Graph
	struct Edge edges[] =
            {
                    {0, 1, 1}, {1, 2, 2}, {2, 3, 3}, {3, 4, 4}, {4, 0, 5}
            };
        
	// calculate the total number of edges
        int n = sizeof(edges)/sizeof(edges[0]);
        
	struct Graph *graph = createGraph(edges, n);
	
	//set all 0 to Inf
	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < len; j++)
		{
			if(graph->adjLists[i][j] == 0 && i != j)
				graph->adjLists[i][j] = INF;
		}
	}

	//call Floyd function
	floydWarshall(graph->adjLists);
}
