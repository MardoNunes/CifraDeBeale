#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

//essa função ira buscar a chave e retornar o valor
//realiza a busca para saber se a chave já existe
//se ele encontrar a chave, adiciona o valor na lista de valores
int busca(struct Lista *lista, char chave, int valor){
    struct nodoDuplo *aux = lista->inicio;
    //percorrendo a lista de chaves
    while(aux != NULL){
        //se a chave for a mesma que estou procurando, adiciona o valor na lista de valores
        if(aux->chave == chave){
            //se a lista de valores estver vazia
            if(aux->valor == NULL){
                struct nodo *novo = malloc(sizeof(struct nodo));
                novo->valor = valor;
                novo->prox = NULL;
                aux->valor = novo;
                return 1;
            }
            else{   //se a lista de valor não estiver vazia
                struct nodo *aux2 = aux->valor;
                while(aux2->prox != NULL){  //percorrendo a lista de valores até o final
                    aux2 = aux2->prox;
                }
                //adiciona o valor no final da lista de valores
                struct nodo *novo = malloc(sizeof(struct nodo));
                novo->valor = valor;
                novo->prox = NULL;
                aux2->prox = novo;
                return 1;
            }
        }
        aux = aux->prox;
    }
    return 0;
}



//estou criando um lista dentro de outra lista
//uma guarda as chaves e a outra os valores ligados a chave
void enqueue(struct Lista *lista, char chave, int valor){
    //verificando se a chave já existe
    if(busca(lista, chave, valor) == 1){
        return;
    }
    //se a cahve ainda nao existir
    //criando a lista de chaves
    struct nodoDuplo *novo = malloc(sizeof(struct nodoDuplo));
    novo->chave = chave;
    
    //criando a lista de valores
    struct nodo *novo_valor = malloc(sizeof(struct nodo));
    novo_valor->valor = valor;
    novo_valor->prox = NULL;
    novo->valor = novo_valor;
    

    //se a lista estiver vazia
    if(lista->inicio == NULL){
        novo->prox = NULL;
        novo->ant = NULL;
        lista->inicio = novo;
        lista->fim = novo;
        novo->valor->prox = NULL;
        novo_valor->prox = NULL;
        
    }
    else{   //se a lista não estiver vazia
        novo->prox = NULL;
        novo->ant = lista->fim;
        lista->fim->prox = novo;
        lista->fim = novo;
        novo->valor->prox = NULL;
        novo_valor->prox = NULL;
    }

}

//esse procdedimento irá destruir a lista
void dequeue(struct Lista *lista){
    struct nodoDuplo *aux = lista->inicio;

    while(aux != NULL){
        struct nodo *aux2 = aux->valor;
        while(aux2 != NULL){
            struct nodo *prox = aux2->prox;
            free(aux2);
            aux2 = prox;
        }
        struct nodoDuplo *prox = aux->prox;
        free(aux);
        aux = prox;
    }
    free(lista);
}



//esse procedimento imprimi as chaves e os valores
void imprimi(struct Lista *lista){
    struct nodoDuplo *aux = lista->inicio;

    while(aux != NULL){
        printf(" %c:\t", aux->chave);
        struct nodo *aux2 = aux->valor;
        while(aux2 != NULL){
            printf("%d\t", aux2->valor);
            aux2 = aux2->prox;
        }
        printf("\n");
        aux = aux->prox;
    }
}



int main(){
    char chave;
    int valor;
    int cont = 0;
    
   //inicio da lista 
    struct Lista *lista = (struct Lista*) malloc(sizeof(struct Lista));
    lista->inicio = NULL;
    lista->fim = NULL;

    while(cont <= 5){
        printf("Entre com a chave: ");
        scanf("%c", &chave);
        getchar();
        printf("Entre com o valor: ");
        scanf("%d", &valor);
        getchar();
        enqueue(lista, chave, valor);
        cont++;
    }
    imprimi(lista);
    dequeue(lista);
    return 0;
}