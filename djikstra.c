#include "djikstra.h"
// Uma fun��o utilit�ria para encontrar o
// v�rtice com dist�ncia m�nima
// value, do conjunto de v�rtices
// ainda n�o inclu�do no menor
// �rvore do caminho
int distanciaMinima(int distancia[], bool sptSet[]){
// Inicializa o valor m�nimo 
    int min = INT_MAX, min_index; 
  	int v;
    for (v = 0; v < V; v++) 
        if (sptSet[v] == false && 
                   distancia[v] <= min) 
            min = distancia[v], min_index = v; 
  
    return min_index; 
} 
  
// Fun��o para imprimir mais curta
// caminho da origem para j
// usando matriz pai
void imprimirCaminho(char **vetorNomes, int parent[], int j) { 
	// Caso base: se j � fonte
    if (parent[j] == - 1) 
        return; 
  
    imprimirCaminho(vetorNomes, parent, parent[j]); 
  
    printf("%s ", vetorNomes[j]); 
} 
  

// Uma fun��o utilit�ria para imprimir
// a dist�ncia constru�da
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
  
// Fun��o que implementa o Dijkstra
// caminho mais curto da fonte �nica
// algoritmo para um gr�fico representado
// usando representa��o da matriz de adjac�ncia 
int dijkstra(char **vetorNomes, int **grafo, int origem, int destino) { 
      
	// A matriz de sa�da. distancia [i]
    // manter� o menor tempo
    // dist�ncia entre origem e i
    int distancia[V];  
    
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
        distancia[i] = INT_MAX; 
        sptSet[i] = false; 
    } 
  
	// Dist�ncia do v�rtice de origem
    // por si s� � sempre 0
    distancia[origem] = 0; 
    
	// Encontre o caminho mais curto
    // para allvertices
    int count;
    for (count = 0; count < V - 1; count++) { 
        // Escolha a dist�ncia m�nima
        // v�rtice do conjunto de
        // v�rtices ainda n�o processados.
        // u � sempre igual a origem
        // na primeira itera��o.
        int u = distanciaMinima(distancia, sptSet); 
  
		// Marcar o v�rtice escolhido
        // como processado 
        sptSet[u] = true; 
        
		// Atualiza o valor distancia do
        // v�rtices adjacentes do
        // escolheu o v�rtice.
        int v;
        for (v = 0; v < V; v++) 
  
            
			// Atualiza distancia [v] somente se for
            // n�o no sptSet, existe
            // uma aresta de u a v, e
            // peso total do caminho de
            // origem para v atrav�s de u � menor
            // que o valor atual de
            // distancia [v]
            if (!sptSet[v] && grafo[u][v] && 
                distancia[u] + grafo[u][v] < distancia[v]) 
            { 
                parent[v] = u; 
                distancia[v] = distancia[u] + grafo[u][v]; 
            }  
    } 
  
    
	// imprime o constru�do
    // matriz de dist�ncia
    imprimirResultado(vetorNomes, distancia, V, parent, destino, origem);
	
	if(distancia[destino] > 1000000 || distancia[destino] < 0 ){
		return 0;
	}
	return distancia[destino];
} 
  
