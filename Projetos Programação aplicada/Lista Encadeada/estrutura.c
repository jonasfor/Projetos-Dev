#include <stdio.h>
#include <stdlib.h>
#include "cablista.h"

struct no {

    int dado;
    struct no *prox;
};

Lista* inicia_lista (){
    Lista* novo_no;
    novo_no = (Lista*)malloc(sizeof(Lista));
    if(novo_no == NULL)printf("ERRO NA CRIACAO DA LISTA");
    else{
        novo_no->dado = NULL;
        novo_no->prox = NULL;
    }
    return novo_no;
}

Lista* cria_no (int dado){
    Lista* novo_no;
    novo_no = (Lista*)malloc(sizeof(Lista));
    if(novo_no == NULL)printf("ERRO NA CRIACAO DE NO");
    else{
        novo_no->dado = dado;
        novo_no->prox = NULL;
    }

    return novo_no;
}

void insere_no (Lista* cabeca, Lista* novo_no){
   if(novo_no!=NULL){
    novo_no->prox = cabeca->prox;
    cabeca->prox = novo_no;
   }
}

void imprime_lista(Lista* cabeca){
    int i=1;
    Lista* no_percorre_lista;
    no_percorre_lista = (Lista*)malloc(sizeof(Lista));
    no_percorre_lista = cabeca;
    while(no_percorre_lista->prox != NULL){
        no_percorre_lista = no_percorre_lista->prox;
        printf("DADO DO NO[%d] : %d\n",i, no_percorre_lista->dado);
        i++;
    }
}

int busca_no(Lista* cabeca, int valor){
    int i=0;
    Lista* no_percorre_lista;
    no_percorre_lista = (Lista*)malloc(sizeof(Lista));
    no_percorre_lista = cabeca;
    while(no_percorre_lista->prox != NULL){
        no_percorre_lista = no_percorre_lista->prox;
        i++;
        if(no_percorre_lista->dado == valor){
            printf("\nVALOR ENCONTRADO NO :: %d\n ", i);
            return 1;
        }
    }
    return 0;
}


