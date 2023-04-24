/*
Biblioteca que contém as funções que são necessárias para o 
processo de Decoder do problema da cifra de Beale

Criado por: 
    Madoqueu F. Nunes
    27/03/2023


*/
#include "libLista.h"

#ifndef __LIBDENCODER__
#define __LIBDENCODER__

//Essa função ira decodificar a mensagem
void decoder(struct Lista *lista, int code, FILE *MensagemDecodificada);

//essa função procura o valor na lista e retorna o caracter correspondente
char buscaDecoder(struct Lista *lista, int code);

#endif