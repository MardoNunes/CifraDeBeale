#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo{
    int valor;
    struct nodo *prox;
};

struct Lista{
    struct nodo *inicio;
    struct nodo *fim;
}; 


struct nodoDuplo{
    
    char chave;
    struct nodo *valor;
    struct nodoDuplo *prox;
    struct nodoDuplo *ant;
};

struct listaDuplaDupla{
    struct nodoDuplo *inicio;
    struct nodoDuplo *fim;
};

void fila (struct Lista *lista, int valor){
    struct nodo *novo = (struct nodo*) malloc(sizeof(struct nodo));
    novo->valor = valor;
    novo->prox = NULL;

    if(lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;
    }
    else{
        lista->fim->prox = novo;
        lista->fim = novo;
    }
}

void enqueue(struct listaDuplaDupla *listaDupla, struct  Lista *lista, char chave, int valor, int cont){
    if(cont == 0){
        struct nodoDuplo *novo = (struct nodoDuplo*) malloc(sizeof(struct nodoDuplo));
        novo->chave = chave;
        fila(lista, valor);
        //aqui crio um nodoDuplo, não ligo ele a nada ainda
        novo->prox = NULL;
        novo->ant = NULL;

        if(listaDupla->inicio == NULL){
        listaDupla->inicio = novo;
        listaDupla->fim = novo;
    }
    }
    fila(lista, valor);
  /*  novo->chave = chave;
    novo->valor = valor;
    fila(lista, valor);
    //aqui crio um nodoDuplo, não ligo ele a nada ainda
    novo->prox = NULL;
    novo->ant = NULL;

   //se a listaDupla estiver vazia, o novo nodoDuplo é o inicio e o fim
    if(listaDupla->inicio == NULL){
        listaDupla->inicio = novo;
        listaDupla->fim = novo;
    }
    else{   //se a listaDupla não estiver vazia, o novo nodoDuplo é inserido no fim
        listaDupla->fim->prox = novo;
        novo->ant = listaDupla->fim;
        listaDupla->fim = novo;
    }*/
}

void imiprimirlistaDupla(struct listaDuplaDupla *listaDupla){
    struct nodoDuplo *aux = malloc(sizeof(struct nodoDuplo));
    aux = listaDupla->inicio;
    struct nodo *aux2 = malloc(sizeof(struct nodo));
    aux2 = aux->valor;
    
    printf("3\n");
    while(aux != NULL){
        printf("1\n");
        printf("chave: %c:\t", aux->chave);
        printf("valor: \t%d\n", aux2->valor);
        aux = aux->prox;
    }
}
int main(){
    int cont = 0;
    char chave;
    int valor;

    //criando e inicializando a listaDupla duplamente encadeada
    struct listaDuplaDupla *listaDupla = (struct listaDuplaDupla*) malloc(sizeof(struct listaDuplaDupla));
    listaDupla->inicio = NULL;
    listaDupla->fim = NULL;

    //crianod e inicializando a listaDupla encadeada
    struct Lista *lista = (struct Lista*) malloc(sizeof(struct Lista));
    lista->inicio = NULL;
    lista->fim = NULL;
    
    printf("Entre com a chave: ");
    scanf("%c", &chave);
    getchar();
    while(cont <= 3){
        
        printf("Entre com o valor: ");
        scanf("%d", &valor);
        getchar();
        enqueue(listaDupla, lista, chave, valor, cont);
        cont++;
    }
    printf("2\n");
    imiprimirlistaDupla(listaDupla);
    free(listaDupla);
    free(lista);
    return 0;
}