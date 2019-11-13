#include "djikstra.h"

int qntdNodo  = 0;
int **graph;

int** alocarMatriz(int Linhas, int Colunas);
void lerArquivo(int op);
void separarDadosDaLinha(char linha[50], int contLinhas);	
int contaNodos(char linha[50]);

int main() {
	// O 2 é passado como parâmetro para
	// a contagem de nós
	lerArquivo(2);
	
    graph = alocarMatriz(qntdNodo, qntdNodo);
	
	printf("-> %d\n\n", qntdNodo);
	
	lerArquivo(1);
    /*int graph[V][V] =  { 
                        { 0, 2, 0, 0, 0, 0}, 
                        { 0, 0, 0, 0, 0, 0}, 
                        { 0, 3, 0, 0, 0, 0}, 
                        { 2, 0, 2, 0, 0, 0},
                        { 0, 0, 10, 5, 0, 4},
                        { 5, 0, 0, 0, 0, 0},
                        
                    };*/

    dijkstra(graph, 5, 1); 
    return 0; 
} 

int** alocarMatriz(int Linhas, int Colunas){ //Recebe a quantidade de Linhas e Colunas como Parâmetro
 
  int i,j; //Variáveis Auxiliares
 
  int **m = (int**)malloc(Linhas * sizeof(int*)); //Aloca um Vetor de Ponteiros
 
  for (i = 0; i < Linhas; i++){ //Percorre as linhas do Vetor de Ponteiros
       m[i] = (int*) malloc(Colunas * sizeof(int)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
       for (j = 0; j < Colunas; j++){ //Percorre o Vetor de Inteiros atual.
            m[i][j] = 0; //Inicializa com 0.
       }
  }
return m; //Retorna o Ponteiro para a Matriz Alocada
}

void lerArquivo(int op){
	char linha[50]; // string armazenara a linha
    FILE *arq;
	int contLinhas = 0;
    arq = fopen("ProblemaSlideCaminhoMínimo.csv","r"); // Abre o arquivo
    if (arq == NULL){  // Se houve erro na abertura
		printf("Problemas na abertura do arquivo\n");
	}else{
		if(op < 2){
			
			fgets(linha, sizeof(linha)-1, arq);
			while(fgets(linha, sizeof(linha)-1, arq) != NULL) { // Loop para ler cada linha do arquivo enquanto houver linhas
				separarDadosDaLinha(linha, contLinhas);
				contLinhas++;
			}
			
		}else{
			fgets(linha, sizeof(linha)-1, arq); // Loop para ler cada linha do arquivo enquanto houver linhas
			contaNodos(linha);
		}
	}
    fclose(arq);
}


void separarDadosDaLinha(char linha[50], int contLinhas){
	char delimitador[] = ";"; // Caracter delimitador
	
    char *info; // Ponteiro para armazenar as informacoes

	int peso;

	int contColunas = 0;
	
	info = strtok(linha, delimitador); // info recebe a primeira string antes do primeiro delimitador da primeira linha
	while(contColunas < qntdNodo) { // Enquanto houver linhas no arquivo
	//Ignorar primeira coluna

		if(contColunas != 0){
			info = strtok(NULL, delimitador);
			peso = atoi(info); // Copia info para peso
			graph[contLinhas][contColunas-1] = peso;
			
		}
		contColunas++;
	}
}


int contaNodos(char linha[50]){
	char delimitador[] = ";"; // Caracter delimitador
    char *info; // Ponteiro para armazenar as informacoes
	
	info = strtok(linha, delimitador); // info recebe a primeira string antes do primeiro delimitador da primeira linha

	while(info != NULL) { // Enquanto houver linhas no arquivo
		printf("%d\n", atoi(info));
		info = strtok(NULL, delimitador); // Separa o nome da linha

		qntdNodo++;
	}
}
