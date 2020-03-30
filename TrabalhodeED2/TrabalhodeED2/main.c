#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"


int main()
{
    int linha, coluna;

    int** matriz;

    char nome_arquivo[30]; //nome do arquivo que sera aberto
    scanf("%s", nome_arquivo);

    Lista* li = cria_lista();

    char modo[3] = "rt"; //modo que o arquivo sera aberto (leitura - etc)
    
    //cria o arquivo nos parametros desejados
    FILE* arquivo = cria_arquivo(nome_arquivo, modo);

    //le atravez do arquivo a quantidade de linhas e colunas na matriz
    fscanf(arquivo ,"%d %d", &linha, &coluna);

    //cria uma matriz com numeros aleatorios
    matriz = cria_matriz(linha, coluna);  

    //insere os numeros do arquivo na matriz
    insere_matriz(matriz, arquivo, linha, coluna);

    int co_linha, co_coluna; //coordenada da posicao inicial na linha e na coluna
    fscanf(arquivo, "%d %d", &co_linha, &co_coluna);

    int num_pos_inicial = matriz[co_linha][co_coluna]; //numero da coordenada da posicao inicial

    Flood_Fill(matriz, linha, coluna, co_coluna, co_linha, num_pos_inicial, 2, li);
    
    //printa na tela a lista obtida apos o uso do flood fill
    imprime_lista(li);

    //exclui a matriz, fecha os arquivos e libera a lista da memoria
    apaga_matriz(matriz, linha); 
    fecha_arquivo(arquivo);
    libera_lista(li);

	return 0;
}