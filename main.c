#include <locale.h>
#include "djikstra.h"

int qntdNodo = 0;
int **grafo;
char **vetorNomes;

int** alocarMatriz(int linhas, int colunas);
void lerArquivo(int op);
void separarDadosDaLinha(char linha[1000], int contLinhas);	
int contaNodos(char linha[1000]);
int pegarIndice(char palavra[100]);
void menu();


int main() {
	setlocale(LC_ALL, "Portuguese_Brazil.1252");
	// O 2 é passado como parâmetro para
	// a contagem de nós
	lerArquivo(2);

	V = qntdNodo;

    grafo = alocarMatriz(qntdNodo, qntdNodo);
	
	lerArquivo(1);
	menu();
    
    return 0; 
} 

int** alocarMatriz(int linhas, int colunas){ //Recebe a quantidade de linhas e colunas como Parâmetro
 
  int i,j; //Variáveis Auxiliares
 
  int **m = (int**)malloc(linhas * sizeof(int*)); //Aloca um Vetor de Ponteiros
 
  for (i = 0; i < linhas; i++){ //Percorre as linhas do Vetor de Ponteiros
       m[i] = (int*) malloc(colunas * sizeof(int)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
       for (j = 0; j < colunas; j++){ //Percorre o Vetor de Inteiros atual.
            m[i][j] = 0; //Inicializa com 0.
       }
  }
return m; //Retorna o Ponteiro para a Matriz Alocada
}

void lerArquivo(int op){
	char linha[1000]; // string armazenara a linha
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


void separarDadosDaLinha(char linha[1000], int contLinhas){
	char delimitador[] = ";"; // Caracter delimitador
	
    char *info; // Ponteiro para armazenar as informacoes
	//printf("-> %s", linha);
	int peso;

	int contColunas = 0;
	
	info = strtok(linha, delimitador); // info recebe a primeira string antes do primeiro delimitador da primeira linha
	while(contColunas < qntdNodo) { // Enquanto houver linhas no arquivo
	//Ignorar primeira coluna

		if(contColunas != 0){
			info = strtok(NULL, delimitador);
			peso = atoi(info); // Copia info para peso
			grafo[contLinhas][contColunas-1] = peso;
			
		}
		contColunas++;
	}
}


int contaNodos(char linha[1000]){
	char delimitador[] = ";"; // Caracter delimitador
    char *info; // Ponteiro para armazenar as informacoes
    int c = 0, aux;
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
		//Tratando o \n
		aux = strstr(info, "\n") - info;
		if(aux > 0) info[aux] = '\0';
		
    	vetorNomes[c] = strdup(info);
    	info = strtok(NULL, delimitador);
	}

}

void menu(){
	char no1[100], no2[100], no3[100], no4[100];
	int distTotal = 0;
	printf("Digite o primeiro no: ");
	gets(no1);
	//scanf("%s", no1);
	setbuf(stdin, NULL);
	
	printf("Digite o segundo no: ");
	gets(no2);
	//scanf("%s", no2);
	setbuf(stdin, NULL);
	
	printf("Digite o terceiro no: ");
	gets(no3);
	//scanf("%s", no3);
	setbuf(stdin, NULL);
	
	printf("Digite o quarto no: ");
	gets(no4);
	//scanf("%s", no4);
	setbuf(stdin, NULL);
	
	printf("\n\n==============================================");
	
	printf("\nVertices\tDistancia \tNos Visitados"); 
	
	distTotal += dijkstra(vetorNomes, grafo, pegarIndice(no1), pegarIndice(no2));
	distTotal += dijkstra(vetorNomes, grafo, pegarIndice(no2), pegarIndice(no3));
	distTotal += dijkstra(vetorNomes, grafo, pegarIndice(no3), pegarIndice(no4));
	
	printf("\n\n==============================================");
	
	printf("\nDistancia Total = %d", distTotal);
	
	printf("\n==============================================\n\n");
}

int pegarIndice(char palavra[100]){
	int count = 0;
	while(count < qntdNodo){
		
		if(!strcmp(vetorNomes[count], palavra)){
			return count;
		}
		
		count++;
	}
}
