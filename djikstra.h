#include <stdio.h> 
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

int V;

int minDistance(int dist[], bool sptSet[]);
void printPath(char **vetorNomes, int parent[], int j);
int printSolution(char **vetorNomes, int dist[], int n, int parent[], int destino, int origem);
int dijkstra(char **vetorNomes, int **graph, int origem, int destino);
