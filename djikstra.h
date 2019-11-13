// Programa C para o single de Dijkstra
// algoritmo de caminho mais curto de origem.
// O programa � para matriz de adjac�ncia
// representa��o do gr�fico.
#include <stdio.h> 
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
  

// N�mero de v�rtices
// no gr�fico
#define V 6

int minDistance(int dist[], bool sptSet[]);
void printPath(int parent[], int j);
int printSolution(int dist[], int n, int parent[], int destino, int src);
void dijkstra(int **graph, int src, int destino);
