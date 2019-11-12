
// Programa C para o single de Dijkstra
// algoritmo de caminho mais curto de origem.
// O programa é para matriz de adjacência
// representação do gráfico.
#include <stdio.h> 
#include <limits.h>
#include <stdbool.h>
  

// Número de vértices
// no gráfico
#define V 6

















  
// Uma função utilitária para encontrar o
// vértice com distância mínima
// value, do conjunto de vértices
// ainda não incluído no menor
// árvore do caminho
int minDistance(int dist[], bool sptSet[]){
// Inicializa o valor mínimo 
    int min = INT_MAX, min_index; 
  	int v;
    for (v = 0; v < V; v++) 
        if (sptSet[v] == false && 
                   dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
  

// Função para imprimir mais curta
// caminho da origem para j
// usando matriz pai
void printPath(int parent[], int j) { 
	// Caso base: se j é fonte
    if (parent[j] == - 1) 
        return; 
  
    printPath(parent, parent[j]); 
  
    printf("%d ", j); 
} 
  

// Uma função utilitária para imprimir
// a distância construída
// array 
int printSolution(int dist[], int n, int parent[], int destino, int src) { 
    //int src = 0; 
    printf("Vertex\t Distance\tPath"); 
    
    //for (destino = 1; destino < V; destino++) 
    //{ 
        printf("\n%d -> %d \t\t %d\t\t%d ", 
                      src, destino, dist[destino], src); 
        printPath(parent, destino); 
    //} 
} 
  
// Função que implementa o Dijkstra
// caminho mais curto da fonte única
// algoritmo para um gráfico representado
// usando representação da matriz de adjacência 
void dijkstra(int graph[V][V], int src, int destino) { 
      
	// A matriz de saída. dist [i]
    // manterá o menor tempo
    // distância entre src e i
    int dist[V];  
    
	// sptSet [i] será verdadeiro se o vértice
    // i está incluído / no mais curto
    // árvore do caminho ou distância mais curta
    // de src para i é finalizado
    bool sptSet[V]; 
    
	// Matriz pai a ser armazenada
    // árvore do caminho mais curto
    int parent[V]; 
    
	// Inicialize todas as distâncias como
    // INFINITE e stpSet [] como false
    int i;
    for (i = 0; i < V; i++) 
    { 
        parent[i] = -1; 
        dist[i] = INT_MAX; 
        sptSet[i] = false; 
    } 
  
	// Distância do vértice de origem
    // por si só é sempre 0
    dist[src] = 0; 
    
	// Encontre o caminho mais curto
    // para allvertices
    int count;
    for (count = 0; count < V - 1; count++) { 
        // Escolha a distância mínima
        // vértice do conjunto de
        // vértices ainda não processados.
        // u é sempre igual a src
        // na primeira iteração.
        int u = minDistance(dist, sptSet); 
  
		// Marcar o vértice escolhido
        // como processado 
        sptSet[u] = true; 
        
		// Atualiza o valor dist do
        // vértices adjacentes do
        // escolheu o vértice.
        int v;
        for (v = 0; v < V; v++) 
  
            
			// Atualiza dist [v] somente se for
            // não no sptSet, existe
            // uma aresta de u a v, e
            // peso total do caminho de
            // src para v através de u é menor
            // que o valor atual de
            // dist [v]
            if (!sptSet[v] && graph[u][v] && 
                dist[u] + graph[u][v] < dist[v]) 
            { 
                parent[v] = u; 
                dist[v] = dist[u] + graph[u][v]; 
            }  
    } 
  
    
	// imprime o construído
    // matriz de distância
    printSolution(dist, V, parent, destino, src); 
} 
  

// Código do Driver 
int main() { 
    
	// Vamos criar o exemplo
    // gráfico discutido acima
    int graph[V][V] =  { 
                        { 0, 2, 0, 0, 0, 0}, 
                        { 0, 0, 0, 0, 0, 0}, 
                        { 0, 3, 0, 0, 0, 0}, 
                        { 2, 0, 2, 0, 0, 0}, 
                        { 0, 0, 10, 5, 0, 4}, 
                        { 5, 0, 0, 0, 0, 0}, 
                        
                    }; 
  	//dijkstra(graph, V, 0, 4); 
    dijkstra(graph, 5, 1); 
    return 0; 
} 
