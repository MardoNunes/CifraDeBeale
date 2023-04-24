
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libEncoder.h"
#include "libLista.h"


//Essa função ira calcular o tamanho da lista de valores e retronar esse tamanho
int tamanho(struct Lista *lista, struct nodoDuplo *aux){
    int size = 0;
    struct nodo *aux2 = aux->valor;
    while(aux2 != NULL){
        size++;
        aux2 = aux2->prox;
    }
    return size;
}

//essa função ira buscar o caracter na lista e retornar um numero para codificar
//ela tambem pega um valor aleatorio da lista de valores
//se não achar o caracter, ira retornar -1
int busca(struct Lista *lista, char chave){
    struct nodoDuplo *aux = lista->inicio;
    int value;
    int size;
    int random;
    while(aux != NULL){ //percorre a lista de chaves
        if(aux->chave == chave){    //se achar a chave, adiciono em value e retorno ess valor
            size = tamanho(lista, aux); //pega o tamanho da lista de valores
            random = rand() % size; //gera um numero aleatorio entre 0 e o tamanho da lista de valores
            //agora ele ira percorre a lista de valores e pegar o valor na posição random
            struct nodo *aux2 = aux->valor;
            for(int i = 0; i < random; i++){
                aux2 = aux2->prox;
            }
            value = aux2->valor;
            
            return value;
        }
        aux = aux->prox;
    }
    return -1;
}


//essa função vai separar cada caracter da string e codificar
void encoder(struct Lista *lista, char mstr, FILE *MensagemCodificada){
        int code;
        if(mstr == '\n')
            code = -2;
        else
            code = busca(lista, mstr);
        fprintf(MensagemCodificada, "%d ", code);
}