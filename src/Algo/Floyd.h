#define _FLOYD_H
#include "../IA/src/attraction.h"
#include "../IA/src/population.h"
#include "Graph.h"
#include <stdio.h>
#define len 12
#define INF 999

void printMatrix(int** matrix);

int** floydWarshall(int** graph, int n);

void printMatrix(int** matrix);

int** FUNCTION(parc* parcGUI, size_t nbAtt);
