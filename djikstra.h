#include <stdio.h> 
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

int V;

int distanciaMinima(int distancia[], bool sptSet[]);
void imprimirCaminho(char **vetorNomes, int parent[], int j);
int imprimirResultado(char **vetorNomes, int distancia[], int n, int parent[], int destino, int origem);
int dijkstra(char **vetorNomes, int **grafo, int origem, int destino);
