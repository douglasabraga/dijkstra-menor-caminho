#include "djikstra.h"
// Uma função utilitária para encontrar o
// vértice com distância mínima
// value, do conjunto de vértices
// ainda não incluído no menor
// árvore do caminho
int distanciaMinima(int distancia[], bool sptSet[]){
// Inicializa o valor mínimo 
    int min = INT_MAX, min_index; 
  	int v;
    for (v = 0; v < V; v++) 
        if (sptSet[v] == false && 
                   distancia[v] <= min) 
            min = distancia[v], min_index = v; 
  
    return min_index; 
} 
  
// Função para imprimir mais curta
// caminho da origem para j
// usando matriz pai
void imprimirCaminho(char **vetorNomes, int parent[], int j) { 
	// Caso base: se j é fonte
    if (parent[j] == - 1) 
        return; 
  
    imprimirCaminho(vetorNomes, parent, parent[j]); 
  
    printf("%s ", vetorNomes[j]); 
} 
  

// Uma função utilitária para imprimir
// a distância construída
// array 
int imprimirResultado(char **vetorNomes, int distancia[], int n, int parent[], int destino, int origem) { 

	if(distancia[destino] > 1000000 || distancia[destino] < 0 ){
		printf("\n%s -> %s \t\t nao existe caminho", vetorNomes[origem], vetorNomes[destino]);
	}else{
		
		printf("\n%s -> %s \t\t %d\t\t%s ", 
		              vetorNomes[origem], vetorNomes[destino], distancia[destino], vetorNomes[origem]); 
		imprimirCaminho(vetorNomes, parent, destino);
		
	}

} 
  
// Função que implementa o Dijkstra
// caminho mais curto da fonte única
// algoritmo para um gráfico representado
// usando representação da matriz de adjacência 
int dijkstra(char **vetorNomes, int **grafo, int origem, int destino) { 
      
	// A matriz de saída. distancia [i]
    // manterá o menor tempo
    // distância entre origem e i
    int distancia[V];  
    
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
        distancia[i] = INT_MAX; 
        sptSet[i] = false; 
    } 
  
	// Distância do vértice de origem
    // por si só é sempre 0
    distancia[origem] = 0; 
    
	// Encontre o caminho mais curto
    // para allvertices
    int count;
    for (count = 0; count < V - 1; count++) { 
        // Escolha a distância mínima
        // vértice do conjunto de
        // vértices ainda não processados.
        // u é sempre igual a origem
        // na primeira iteração.
        int u = distanciaMinima(distancia, sptSet); 
  
		// Marcar o vértice escolhido
        // como processado 
        sptSet[u] = true; 
        
		// Atualiza o valor distancia do
        // vértices adjacentes do
        // escolheu o vértice.
        int v;
        for (v = 0; v < V; v++) 
  
            
			// Atualiza distancia [v] somente se for
            // não no sptSet, existe
            // uma aresta de u a v, e
            // peso total do caminho de
            // origem para v através de u é menor
            // que o valor atual de
            // distancia [v]
            if (!sptSet[v] && grafo[u][v] && 
                distancia[u] + grafo[u][v] < distancia[v]) 
            { 
                parent[v] = u; 
                distancia[v] = distancia[u] + grafo[u][v]; 
            }  
    } 
  
    
	// imprime o construído
    // matriz de distância
    imprimirResultado(vetorNomes, distancia, V, parent, destino, origem);
	
	if(distancia[destino] > 1000000 || distancia[destino] < 0 ){
		return 0;
	}
	return distancia[destino];
} 
  
