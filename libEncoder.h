/*
Biblioteca que contém as funções que são necessárias para o 
processo de Encoder do problema da cifra de Beale

Criado por: 
    Madoqueu F. Nunes
    27/03/2023


*/

#include "libLista.h"

#ifndef __LIBENCODER__
#define __LIBENCODER__

//Essa função ira calcular o tamanho da lista de valores e retronar esse tamanho
int tamanho(struct Lista *lista, struct nodoDuplo *aux);

//Essa função vai separar cada caracter da string e codificar
void encoder(struct Lista *lista, char mstr, FILE *ArquivoDeChaves);

//Essa função busca o caracter na lista e devolve um valor para codificar
int busca(struct Lista *lista, char chave);

#endif