#include "djikstra.h"
// Uma fun��o utilit�ria para encontrar o
// v�rtice com dist�ncia m�nima
// value, do conjunto de v�rtices
// ainda n�o inclu�do no menor
// �rvore do caminho
int minDistance(int dist[], bool sptSet[]){
// Inicializa o valor m�nimo 
    int min = INT_MAX, min_index; 
  	int v;
    for (v = 0; v < V; v++) 
        if (sptSet[v] == false && 
                   dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
  
// Fun��o para imprimir mais curta
// caminho da origem para j
// usando matriz pai
void printPath(char **vetorNomes, int parent[], int j) { 
	// Caso base: se j � fonte
    if (parent[j] == - 1) 
        return; 
  
    printPath(vetorNomes, parent, parent[j]); 
  
    printf("%s ", vetorNomes[j]); 
} 
  

// Uma fun��o utilit�ria para imprimir
// a dist�ncia constru�da
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
  
// Fun��o que implementa o Dijkstra
// caminho mais curto da fonte �nica
// algoritmo para um gr�fico representado
// usando representa��o da matriz de adjac�ncia 
int dijkstra(char **vetorNomes, int **graph, int origem, int destino) { 
      
	// A matriz de sa�da. dist [i]
    // manter� o menor tempo
    // dist�ncia entre origem e i
    int dist[V];  
    
	// sptSet [i] ser� verdadeiro se o v�rtice
    // i est� inclu�do / no mais curto
    // �rvore do caminho ou dist�ncia mais curta
    // de origem para i � finalizado
    bool sptSet[V]; 
    
	// Matriz pai a ser armazenada
    // �rvore do caminho mais curto
    int parent[V]; 
    
	// Inicialize todas as dist�ncias como
    // INFINITE e stpSet [] como false
    int i;
    for (i = 0; i < V; i++) 
    { 
        parent[i] = -1; 
        dist[i] = INT_MAX; 
        sptSet[i] = false; 
    } 
  
	// Dist�ncia do v�rtice de origem
    // por si s� � sempre 0
    dist[origem] = 0; 
    
	// Encontre o caminho mais curto
    // para allvertices
    int count;
    for (count = 0; count < V - 1; count++) { 
        // Escolha a dist�ncia m�nima
        // v�rtice do conjunto de
        // v�rtices ainda n�o processados.
        // u � sempre igual a origem
        // na primeira itera��o.
        int u = minDistance(dist, sptSet); 
  
		// Marcar o v�rtice escolhido
        // como processado 
        sptSet[u] = true; 
        
		// Atualiza o valor dist do
        // v�rtices adjacentes do
        // escolheu o v�rtice.
        int v;
        for (v = 0; v < V; v++) 
  
            
			// Atualiza dist [v] somente se for
            // n�o no sptSet, existe
            // uma aresta de u a v, e
            // peso total do caminho de
            // origem para v atrav�s de u � menor
            // que o valor atual de
            // dist [v]
            if (!sptSet[v] && graph[u][v] && 
                dist[u] + graph[u][v] < dist[v]) 
            { 
                parent[v] = u; 
                dist[v] = dist[u] + graph[u][v]; 
            }  
    } 
  
    
	// imprime o constru�do
    // matriz de dist�ncia
    printSolution(vetorNomes, dist, V, parent, destino, origem);
	
	if(dist[destino] < 0 ){
		return 0;
	}
	return dist[destino];
} 
  
