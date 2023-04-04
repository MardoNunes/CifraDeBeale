/*
Biblioteca que contém as funções e a estrutura que armazenará meus valores para 
a resolução do problema 'cifra de Beale'

Criado por: 
    Madoqueu F. Nunes
    31/03/2023


*/

#ifndef __LIBBEALE__
#define __LIBBEALE__


//estrutura que armazenará os valores
struct nodo{
    int valor;
    struct nodo *prox;
};

struct nodoDuplo{
    char chave;
    struct nodo *valor;
    struct nodoDuplo *prox;
    struct nodoDuplo *ant;
};

struct Lista{
    struct nodoDuplo *inicio;
    struct nodoDuplo *fim;
};

//funções
int busca(struct Lista *lista, char chave, int valor);
void enqueue(struct Lista *lista, char chave, int valor);
void dequeue(struct Lista *lista);
void imprimi(struct Lista *lista);




#endif