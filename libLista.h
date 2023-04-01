/*
Biblioteca que contém as funções e a estrutura para a resolução
 do problema 'cifra de Beale'

Criado por: 
    Madoqueu F. Nunes
    31/03/2023


*/

struct nodo{
    char c;
    int *chave;

    struct nodo *prox;
    struct nodo *ant;
};

struct lista{
    int tam;
    struct nodo *fim;
    struct nodo *cabeca;
};

