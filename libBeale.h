/*
Biblioteca que contém as funções de checagem 
de argumento para o problema da cifra de Beale

Criado por: 
    Madoqueu F. Nunes
    27/03/2023


*/

#include "libLista.h"

#ifndef __LIBBEALE__
#define __LIBBEALE__


//Essa função irá printar a mensagem de erro
void error();

//Essa função ira checar se o numero de agurmentos passados é valido
//E se tais argumentos estão corretos
int checkall(int argc, char **argv);

//Essa função irá transformar todas as letras maiusculas em minusculas
void minuscula(char *str);

//Essa função testa se os arquivos foram abertos corretamente
void testArq(FILE *arq);


//Essa função vai separar cada caracter da string e codificar
void encoder(struct Lista *lista, char *mstr);

//Essa função busca o caracter na lista e devolve um valor para codificar
int busca(struct Lista *lista, char chave);



#endif