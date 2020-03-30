#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

Lista* cria_lista() //Função que cria uma lista dinamicamente encadeada dupla
{
    Lista* li = (Lista*)malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li) //Função que libera a lista que foi criada dinamicamente
{
    if (li != NULL)
    {
        Elem* no;
        while ((*li) != NULL)
        {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}


int insere_lista_ordenada(Lista* li, Tipo_Dado dt) // Função que insere na lista já de forma ordenada,segundo dois parametros,inicialmente a coordenada x e depois a y.
{
    if (li == NULL)
        return ERRO;
    Elem* no = (Elem*)malloc(sizeof(Elem));
    if (no == NULL)
        return ERRO;
    no->dado = dt;
    if ((*li) == NULL)
    {  //lista vazia: insere início
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return OK;
    }
    else {
        Elem* ante, * atual = *li;
        ante = atual;
        while (atual != NULL && (atual->dado.linha < dt.linha || (atual->dado.linha == dt.linha && atual->dado.coluna <= dt.coluna)))
        {
            ante = atual;
            atual = atual->prox;
        }
        if (atual == *li)
        {   //insere início
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        }
        else
        {
            no->prox = ante->prox;
            no->ant = ante;
            ante->prox = no;
            if (atual != NULL)
                atual->ant = no;
        }

        return OK;
    }
}


int tamanho_lista(Lista* li) //Retorna o tamanho total da lista
{
    if (li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while (no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}


void imprime_lista(Lista* li) //Imprime a lista
{
    Elem* no = *li;

    if (li == NULL)
        return;
    while (no != NULL)
    {
        printf("%d %d\n", no->dado.linha, no->dado.coluna);
        no = no->prox;
    }
}