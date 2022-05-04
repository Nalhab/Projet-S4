#include "Graph.h"
#include <stdio.h>
#define len 5  //Number of vertice 
#define INF 999

void printMatrix(int matrix[][len]);

void floydWarshall(int** graph, int n) 
{
	int res[n][n];
       	int i, j, k;
	
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			res[i][j] = graph[i][j];

	for (k = 0; k < n; k++) 
	{
		for (i = 0; i < n; i++) 
		{
			for (j = 0; j < n; j++) 
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
		printf("Dist from vertex number %d-->  ", i);
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
		    //, {0, 3, 1},{3, 0, -2}
            };
	int n = 5;
	int l = sizeof(edges)/sizeof(edges[0]);
    	struct list* List = malloc(sizeof(struct list));
        List->data = edges[0];
	for(int i = 1; i < l; i++)
        {
                struct list* nList = malloc(sizeof(struct list));
                nList->data = edges[i];
                list_push_front(List, nList);
		//printf("%d, %d\n" ,edges[i].src,edges[i].dest); //Visualisation de 
		//l'ajout des liaisons dans la liste
        } 
        //printf("\n");
	struct Graph *graph = createGraph(n, List, l);
	
	//Liste d'adjacense du Graph
	/*for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%d ", graph->adjLists[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/

	printf("Edges of the Graph :\n\n");
	printGraph(graph, n);
	//set all 0 to Inf
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(graph->adjLists[i][j] == 0 && i != j)
				graph->adjLists[i][j] = INF;
		}
	}
	printf("\n");

	printf("Result of the Floyd algorithm :\n\n");
	//call Floyd function
	floydWarshall(graph->adjLists, n);
}
