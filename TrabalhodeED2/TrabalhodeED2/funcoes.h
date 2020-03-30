#include <stdio.h>
#include <stdlib.h>

//Definindo variáveis booleanas
#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0

//Definindo a struct coord como um novo tipo de dado
typedef struct coord  Tipo_Dado;

//Criando uma struct que representa um ponto(Coordenadas x e y)
struct coord {
    int linha;
    int coluna;
};

//DefiniÃ§Ã£o do tipo lista
struct elemento { //Criando uma struct que contem o conteudo da struct coord e o elemento anterior e posterior a ele
    struct elemento* ant;
    Tipo_Dado dado;
    struct elemento* prox;
};

typedef struct elemento Elem;

typedef struct elemento* Lista;

//Protótipos das funções referentes a LDED colocados no arquivo Lista.c
Lista* cria_lista(); //Função que cria uma lista dinamicamente encadeada dupla
void libera_lista(Lista* li); //Função que libera a lista que foi criada dinamicamente
int insere_lista_ordenada(Lista* li, Tipo_Dado dt); // Função que insere na lista já de forma ordenada,segundo dois parametros,inicialmente a coordenada x e depois a y.
int tamanho_lista(Lista* li); //Retorna o tamanho total da lista
void imprime_lista(Lista* li); //Imprime a lista

//funcoes referentes ao flood_fill, matriz e ao arquivo colocados no arquivo funcoes.c
int** cria_matriz(int quant_num_x, int quant_num_y); //cria uma matriz com numeros aleatorios e retorna ela inteira
FILE* cria_arquivo(char nome_arquivo[30], char modo[3]); //abre o arquivo dejesado no modo desejado
void insere_matriz(int** matriz, FILE* arquivo, int linha, int coluna); //insere na matriz os dados do arquivo aberto na main do codigo
void Flood_Fill(int** matriz,int linha,int coluna,int co_coluna,int co_linha,int num_pos_inicial,int cor_nova, Lista* li); //Algoritmo de  preenchimento, flood fill
void apaga_matriz(int** matriz, int linhas); //exclui a matriz alocada dinamicamente
void fecha_arquivo(FILE *arquivo); //fecha o arquivo aberto no codigo

