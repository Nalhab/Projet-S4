#include "Floyd.h"
#include <stdio.h>

void printMatrix(int** matrix);

int** floydWarshall(int** graph, int n) 
{
	int** res = calloc(n, sizeof(int*));
	for(int i = 0; i < n; i++)
        {
                res[i] = calloc(n,sizeof(int));
        }	
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
	return res;
}

void printMatrix(int** matrix)
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

void adjList_refresh(parc* parcGUI, int n, struct Graph* graph)
{
        for(size_t i = 1; i < (size_t)n; i++)
        {
		attraction* att = *(parcGUI->att + i- 1);
		int val = (att->nbpeople / 10)*5;
                for(size_t j = 0; j < (size_t)n; j++)
                {
			if( i != j)
			{
                        	graph->adjLists[j][i] += val;
                	}
			/*graph->adjLists[0][1] = 20;
			graph->adjLists[2][1] = 20;
			graph->adjLists[3][1] = 20;
			graph->adjLists[4][1] = 20;
			graph->adjLists[5][1] = 20;
			graph->adjLists[6][1] = 20;
			graph->adjLists[7][1] = 20;
			graph->adjLists[8][1] = 20;
			graph->adjLists[9][1] = 20;
			graph->adjLists[10][1] = 20;
			graph->adjLists[11][1] = 20;*/
		}

        }
}

int** FUNCTION(parc* parcGUI) {
	//All edges of the Graph
        struct Edge edges[] =
            {
                    {0, 1, 1}, {0, 2, 2}, {0, 3, 3}, {0, 4, 1}, {0, 5, 2},
		    {0, 6, 1}, {0, 7, 1}, {0, 8, 4}, {0, 9, 3}, {0, 10, 2},
		    {0, 11, 1},
		    {1, 2, 1}, {1, 3, 2}, {1, 4, 3}, {1, 4, 4}, {1, 6, 5},
		    {1, 7, 1}, {1, 8, 2}, {1, 9, 1}, {1, 10, 1}, {1, 11, 2},
		    {2, 3, 1}, {2, 4, 2}, {2, 5, 3}, {2, 6, 4}, {2, 7, 2},
		    {2, 8, 3}, {2, 9, 2}, {2, 10, 2}, {2, 11, 3},
		    {3, 4, 1}, {3, 5, 2}, {3, 6, 3}, {3, 7, 1}, {3, 8, 2},
		    {3, 9, 1}, {3, 10, 1}, {3, 11, 2},
		    {4, 5, 1}, {4, 6, 2}, {4, 7, 3}, {4, 8, 2}, {4, 9, 1},
		    {4, 10, 1}, {4, 11, 2},
		    {5, 6, 1}, {5, 7, 2}, {5, 8, 3}, {5, 9, 4}, {5, 10, 2},
		    {5, 11, 2},
		    {6, 7, 1}, {6, 8, 2}, {6, 9, 3}, {6, 10, 1}, {6, 11, 2},
		    {7, 8, 1}, {7, 9, 2}, {7, 10, 3}, {7, 11, 4},
		    {8, 9, 1}, {8, 10, 2}, {8, 11, 3},
		    {9, 10, 1}, {9, 11, 2},
		    {10, 11, 1}  
            };
	int n = 12;
	int l = sizeof(edges)/sizeof(edges[0]);
    	struct list* List = malloc(sizeof(struct list));
        List->data = edges[0];
	list_init(List);
	for(int i = 1; i < l; i++)
        {
                struct list* nList = malloc(sizeof(struct list));
                nList->data = edges[i];
		list_init(nList);
                list_push_front(List, nList);
		//printf("%d, %d\n" ,edges[i].src,edges[i].dest); //Visualisation de 
		//l'ajout des liaisons dans la liste
        }
        //printf("\n");
	struct Graph *graph = createGraph(n, List, l);
	adjList_refresh(parcGUI, n, graph);
	//Liste d'adjacense du Graph
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%d ", graph->adjLists[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("Edges of the Graph :\n\n");
	//printGraph(graph, n);
	//set all 0 to Inf
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(graph->adjLists[i][j] == 0 && i != j)
				graph->adjLists[i][j] = INF;
		}
	}
	//adjList_refresh(parcGUI, n, graph);
	
	printf("\n");
	printf("Result of the Floyd algorithm :\n\n");
	
	//call Floyd function
	int **res = floydWarshall(graph->adjLists, n);
	return res;
}
