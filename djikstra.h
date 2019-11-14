#include <stdio.h> 
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

#define V 6

int minDistance(int dist[], bool sptSet[]);
void printPath(int parent[], int j);
int printSolution(int dist[], int n, int parent[], int destino, int src);
int dijkstra(int **graph, int src, int destino);
