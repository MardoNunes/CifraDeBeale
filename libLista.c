#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libLista.h"



//essa função ira buscar a chave e retorna 1 se achar e 0 se não achar
//realiza a busca para saber se a chave já existe
//se ele encontrar a chave, adiciona o valor na lista de valores
int verefica(struct Lista *lista, char chave, int valor){
    struct nodoDuplo *aux = lista->inicio;
    //percorrendo a lista de chaves
    while(aux != NULL){
        //se a chave for a mesma que estou procurando, adiciona o valor na lista de valores
        if(aux->chave == chave){
            //se a lista de valores estver vazia
            if(aux->valor == NULL){
                struct nodo *novo = malloc(sizeof(struct nodo));
                novo->valor = valor;
                novo->prox = NULL;
                aux->valor = novo;
                return 1;
            }
            else{   //se a lista de valor não estiver vazia
                struct nodo *aux2 = aux->valor;
                while(aux2->prox != NULL){  //percorrendo a lista de valores até o final
                    aux2 = aux2->prox;
                }
                //adiciona o valor no final da lista de valores
                struct nodo *novo = malloc(sizeof(struct nodo));
                novo->valor = valor;
                novo->prox = NULL;
                aux2->prox = novo;
                return 1;
            }
        }
        aux = aux->prox;
    }
    return 0;
}



//estou criando um lista dentro de outra lista
//uma guarda as chaves e a outra os valores ligados a chave
void enqueue(struct Lista *lista, char chave, int valor){
    //verificando se a chave já existe
    if(verefica(lista, chave, valor) == 1){
        return;
    }
    //se a chave ainda nao existir
    //criando a lista de chaves
    struct nodoDuplo *novo = malloc(sizeof(struct nodoDuplo));
    novo->chave = chave;
    
    //criando a lista de valores
    struct nodo *novo_valor = malloc(sizeof(struct nodo));
    novo_valor->valor = valor;
    novo_valor->prox = NULL;
    novo_valor->ant = NULL;
    novo->valor = novo_valor;   //aqui ligo a chave a lista de valores daquela chave
    

    //se a lista estiver vazia
    if(lista->inicio == NULL){
        novo->prox = NULL;
        novo->ant = NULL;
        lista->inicio = novo;
        lista->fim = novo;
        novo->valor->prox = NULL;
        novo_valor->prox = NULL;
        novo_valor->ant = NULL;
        
    }
    else{   //se a lista não estiver vazia
        novo->prox = NULL;
        novo->ant = lista->fim;
        lista->fim->prox = novo;
        lista->fim = novo;
        novo->valor->prox = NULL;
        novo_valor->ant = novo_valor->prox;
        novo_valor->prox = NULL;

    }
}

//esse procdedimento irá destruir a lista
void dequeue(struct Lista *lista){
    struct nodoDuplo *aux = lista->inicio;

    //percorrendo a lista de chaves
    while(aux != NULL){

        struct nodo *aux2 = aux->valor;
        //percorrendo a lista de valores
        while(aux2 != NULL){
            struct nodo *prox = aux2->prox;
            free(aux2); //liberando a memoria da lista de valores
            aux2 = prox;
        }
        struct nodoDuplo *prox = aux->prox;
        free(aux); //o mesmo para a lista de chaves
        aux = prox;
    }
    free(lista);
}



//esse procedimento imprimi as chaves e os valores
void imprimi(struct Lista *lista, FILE *ArquivoDeChaves){
    struct nodoDuplo *aux = lista->inicio;

    while(aux != NULL){
        fprintf(ArquivoDeChaves, "%c: ", aux->chave);
        struct nodo *aux2 = aux->valor;
        while(aux2 != NULL){
            fprintf(ArquivoDeChaves, "%d ", aux2->valor);
            aux2 = aux2->prox;
        }
        fprintf(ArquivoDeChaves,"\n");
        aux = aux->prox;
    }
}




