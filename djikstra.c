#include "djikstra.h"
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
void printPath(char **vetorNomes, int parent[], int j) { 
	// Caso base: se j é fonte
    if (parent[j] == - 1) 
        return; 
  
    printPath(vetorNomes, parent, parent[j]); 
  
    printf("%s ", vetorNomes[j]); 
} 
  

// Uma função utilitária para imprimir
// a distância construída
// array 
int printSolution(char **vetorNomes, int dist[], int n, int parent[], int destino, int src) { 
    //int src = 0; 
    
    //for (destino = 1; destino < V; destino++) 
    //{ 
	if(dist[destino] < 0 ){
		printf("\n%s -> %s \t\t nao existe caminho", vetorNomes[src], vetorNomes[destino]);
	}else{
		
		printf("\n%s -> %s \t\t %d\t\t%s ", 
		              vetorNomes[src], vetorNomes[destino], dist[destino], vetorNomes[src]); 
		printPath(vetorNomes, parent, destino);
		
	}
       // distTotal += dist[destino];
    //} 
} 
  
// Função que implementa o Dijkstra
// caminho mais curto da fonte única
// algoritmo para um gráfico representado
// usando representação da matriz de adjacência 
int dijkstra(char **vetorNomes, int **graph, int origem, int destino) { 
      
	// A matriz de saída. dist [i]
    // manterá o menor tempo
    // distância entre origem e i
    int dist[V];  
    
	// sptSet [i] será verdadeiro se o vértice
    // i está incluído / no mais curto
    // árvore do caminho ou distância mais curta
    // de origem para i é finalizado
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
    dist[origem] = 0; 
    
	// Encontre o caminho mais curto
    // para allvertices
    int count;
    for (count = 0; count < V - 1; count++) { 
        // Escolha a distância mínima
        // vértice do conjunto de
        // vértices ainda não processados.
        // u é sempre igual a origem
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
            // origem para v através de u é menor
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
    printSolution(vetorNomes, dist, V, parent, destino, origem);
	
	if(dist[destino] < 0 ){
		return 0;
	}
	return dist[destino];
} 
  
