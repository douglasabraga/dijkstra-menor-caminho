

#include "djikstra.h"

int qntdNodo = 0;
int **graph;
char **vetorNomes;

int** alocarMatriz(int Linhas, int Colunas);
void lerArquivo(int op);
void separarDadosDaLinha(char linha[50], int contLinhas);	
int contaNodos(char linha[50]);
void menu();


int main() {
	// O 2 é passado como parâmetro para
	// a contagem de nós
	lerArquivo(2);
	
    graph = alocarMatriz(qntdNodo, qntdNodo);
	
	lerArquivo(1);
	menu();
    
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
			//fgets(linha, sizeof(linha)-1, arq); // Loop para ler cada linha do arquivo enquanto houver linhas
			fgets(linha, sizeof(linha)-1, arq); // Loop para ler cada linha do arquivo enquanto houver linhas
			contaNodos(linha);
		}
	}
    fclose(arq);
}


void separarDadosDaLinha(char linha[50], int contLinhas){
	char delimitador[] = ";"; // Caracter delimitador
	
    char *info; // Ponteiro para armazenar as informacoes
	printf("-> %s", linha);
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
    int c = 0;
    char nome[50];
    strcpy(nome, linha);
	
	
	
	info = strtok(linha, delimitador); // info recebe a primeira string antes do primeiro delimitador da primeira linha
	
	while(info != NULL) { // Enquanto houver linhas no arquivo
		//printf("%d\n", atoi(info));
		info = strtok(NULL, delimitador); // Separa o nome da linha

		qntdNodo++;
	}
	
	
	
	vetorNomes = (char **) malloc( qntdNodo * sizeof( char * ) );

	info = strtok(nome, delimitador);
	
	for(c = 0; c < qntdNodo; c++){ //Loop para percorrer todos os índices do seu "vetor"
		
    	vetorNomes[c] = strdup(info);
    	info = strtok(NULL, delimitador);
	}
	
	for( c = 0; c < qntdNodo ; c++ )
{
 printf( "Elemento: %d - Conteúdo: %s\n", c, vetorNomes[c] );
}


	
}

void menu(){
	int no1, no2, no3, no4, distTotal = 0;
	printf("Digite o primeiro no: ");
	scanf("%d", &no1);
	printf("Digite o segundo no: ");
	scanf("%d", &no2);
	printf("Digite o terceiro no: ");
	scanf("%d", &no3);
	printf("Digite o quarto no: ");
	scanf("%d", &no4);
	printf("\n\n==============================================");
	
	printf("\nVertices\tDistancia \tNos Visitados"); 
	
	distTotal += dijkstra(graph, no1, no2);
	distTotal += dijkstra(graph, no2, no3);
	distTotal += dijkstra(graph, no3, no4);
	
	printf("\n\n==============================================");
	
	printf("\nDistancia Total = %d", distTotal);
	
	printf("\n==============================================\n\n");
}
