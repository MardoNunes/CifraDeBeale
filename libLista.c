#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libLista.h"

//Aloca a struct
void initLista(){
    struct lista *Lista = malloc(sizeof(struct lista));
    if(Lista == NULL){
        printf("Erro ao alocar Lista!!\n");
        exit(1);
    }
}

//enfilera a struct
void enqueue(struct lista *Lista, char c, int *chave){
    struct lista *novo = (struct lista *)malloc(sizeof(struct lista));
    initLista(novo);
    
    //Aqui eu crio um nodo solto, sem ligações
    novo->prox = NULL;
    novo->ant = NULL;

    //Aqui eu verifico se a lista está vazia
    if(Lista->cabeca == NULL){
        Lista->cabeca = novo;
        Lista->fim = novo;
    }
    else{
        //Aqui eu ligo o novo nodo ao fim da lista
    }

}