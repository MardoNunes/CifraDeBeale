#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libDecoder.h"
#include "libLista.h"

//essa função vai buscar o caracter na lista de chaves
//ele percorrera a lista de chaves e comparar o valor passado com cada valor daquela chave
//E retorna o caracter daquela chave se encontrar
char buscaDecoder(struct Lista *lista, int code){
    //vou percorre a lista de chaves
    struct nodoDuplo *aux  = lista->inicio;
    while(aux != NULL){
        //agora percorra a lista de valores comparando com o valor passado
        struct nodo *aux2 = aux->valor;
        while(aux2 != NULL){
            if(aux2->valor == code){
                return aux->chave;
            }
            aux2 = aux2->prox;
        }
        aux = aux->prox;
    }

    return ' ';
}




//essa função vai decodificar a mensagem
void decoder(struct Lista *lista, int code, FILE *MensagemDecodificada){
    char chave;
    if(code == -1)
        fprintf(MensagemDecodificada, " ");
    else if(code == -2)
        fprintf(MensagemDecodificada, "\n");
    else{
        chave = buscaDecoder(lista, code);
        if(chave != ' ')
            fprintf(MensagemDecodificada, "%c", chave);
        else{
            printf("Não foi possivel decodificar a mensagem!\n");
            exit(1);        
        }
    }
}