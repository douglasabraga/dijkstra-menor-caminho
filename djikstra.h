// Programa C para o single de Dijkstra
// algoritmo de caminho mais curto de origem.
// O programa é para matriz de adjacência
// representação do gráfico.
#include <stdio.h> 
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
  

// Número de vértices
// no gráfico
#define V 6

int minDistance(int dist[], bool sptSet[]);
void printPath(int parent[], int j);
int printSolution(int dist[], int n, int parent[], int destino, int src);
void dijkstra(int **graph, int src, int destino);
