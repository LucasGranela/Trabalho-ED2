#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>

int** cria_matriz(int linhas, int colunas)
{ //Retorna um matriz criada dinamicamente e com "lixo" da memoria
    int i;
    int** matriz = (int**)malloc(linhas * sizeof(int*));
    for (i = 0; i < linhas; i++) {
        matriz[i] = (int*)malloc(colunas * sizeof(int));
    }
    return matriz;
}

void insere_matriz(int** matriz, FILE* arquivo, int linha, int coluna)
{ //insere na matriz os dados do arquivo aberto na main do codigo
    int i, j;

    //percorrer todas as linhas e colunas da matriz
    for ( i = 0; i < linha; i++) {
        for ( j = 0; j < coluna; j++) {
            
            fscanf(arquivo, "%d", &matriz[i][j]);
        
        }
    }
}

void Flood_Fill(int** matriz, int linha, int coluna, int co_coluna, int co_linha, int num_pos_inicial, int cor_nova, Lista* li)
/*
    linha = quantidades de linha que tem na matriz
    coluna =  quantidade de colunas que tem na matriz
    co_coluna = numero da coluna que a funcao esta verificando
    co_linha = numero da linha que a funcao esta verificando
    num_pos_inicial =  numero inicial que a flood fill esta comparando 
*/
{ //Algoritmo de  preenchimento, flood fill
    if (co_coluna < 0 || co_coluna >= coluna || co_linha < 0 || co_linha >= linha) 
        return; //Verificando se a posicao do no durante a recursao e valida,ou seja, se existe na matriz,caso nao exista retorna para a recursao anterior
    if (matriz[co_linha][co_coluna] != num_pos_inicial) 
        return; //Caso a cor de um no adjacente nao for igual a cor de origem retorna para a recursao anterior
    
    Tipo_Dado Dado;
    
    matriz[co_linha][co_coluna] = cor_nova; //Se o no adjacente for igual a cor de origem a cor sera trocada para um nova,como propoe o metodo flood_fill
    
    Dado.coluna = co_coluna;
    Dado.linha = co_linha;
    insere_lista_ordenada(li, Dado);
    
    //Verificando todos os 8 possiveis posicoes dos nos ao redor(quadrado em volta do no a ser analisado)
    Flood_Fill(matriz, linha, coluna, co_coluna + 1, co_linha, num_pos_inicial, cor_nova, li);
    Flood_Fill(matriz, linha, coluna, co_coluna + 1, co_linha + 1, num_pos_inicial, cor_nova, li);
    Flood_Fill(matriz, linha, coluna, co_coluna + 1, co_linha - 1, num_pos_inicial, cor_nova, li);
    Flood_Fill(matriz, linha, coluna, co_coluna, co_linha + 1, num_pos_inicial, cor_nova, li);
    Flood_Fill(matriz, linha, coluna, co_coluna, co_linha - 1, num_pos_inicial, cor_nova, li);
    Flood_Fill(matriz, linha, coluna, co_coluna - 1, co_linha, num_pos_inicial, cor_nova, li);
    Flood_Fill(matriz, linha, coluna, co_coluna - 1, co_linha + 1, num_pos_inicial, cor_nova, li);
    Flood_Fill(matriz, linha, coluna, co_coluna - 1, co_linha - 1, num_pos_inicial, cor_nova, li);
}

void apaga_matriz(int** matriz, int linhas)
{ //libera a matriz alocada dinamicamente da memoria
    int i;
    for (i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

void fecha_arquivo(FILE* arquivo)
{  //fecha o arquivo aberto no codigo
    fclose(arquivo);
}

FILE* cria_arquivo(char nome_arquivo[30], char modo[3])
{ //abre o arquivo dejesado no modo desejado
    FILE* arquivo;

    arquivo = fopen(nome_arquivo, modo);
    
    //se ocorrer algum erro na abertura do arquivo o programa sera fechado
    if (arquivo == NULL)
    {
        printf("Erro na abertura do arquivo\nO aplicativo será fechado!!");
        exit(0);
    }
    
    return arquivo;
}

