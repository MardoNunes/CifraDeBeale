/*
Biblioteca que contém as funções e a estrutura que armazenará meus valores para 
a resolução do problema 'cifra de Beale'

Criado por: 
    Madoqueu F. Nunes
    31/03/2023


*/

#ifndef __LIBLISTA__
#define __LIBLISTA__


//estrutura que armazenará os valores
struct nodo{
    int valor;
    int size;
    struct nodo *prox;
    struct nodo *ant;
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
int verefica(struct Lista *lista, char chave, int valor);
void enqueue(struct Lista *lista, char chave, int valor);
void dequeue(struct Lista *lista);
void imprimi(struct Lista *lista, FILE *ArquivoDeChaves);

#endif