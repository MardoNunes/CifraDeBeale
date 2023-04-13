#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libBeale.h"
#include "libLista.h"


void error(){
    printf("Algum argumento inválido!\n");
    printf("Tente -e para enconder ou -d para decoder!\n");
    printf("Tente -c para decodificar comarquivo chave ou -b para decodificar livro cifra!\n");
}

int checkall(int argc, char **argv){
    if(argc != 8 && argc != 10){
        return -1;
    }
    else if(argv[1][1] == 'e' && argv[2][1] == 'b' && argv[4][1] == 'm' && argv[6][1] == 'o' && argv[8][1] == 'c'){ //fazer processamento de enconder
            //fazer processamento de enconder
            printf("Processando enconder...\n");
            return 1;
            
        }
        else if(argv[1][1] == 'd' && argv[2][1] == 'i' && argv[4][1] == 'c' && argv[6][1] == 'o'){ //fazer processamento de decoder
                //fazer processamento de decoder com arquivo chave
                printf("Processando decoder(arquivio chave)...\n"); 
                return 2;
                
            }
        else if(argv[1][1] == 'd' && argv[2][1] == 'i' && argv[4][1] == 'b' && argv[6][1] == 'o'){
                //fazer processamento de decoder com livro cifra
                printf("Processando decoder(livro cifra)...\n");
                return 3;
                
            }
        else{
            return -1;
        }
}
    
//esse função tranformará as string em minusculas
void minusculaStr(char *str){
    int i;
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + 32;
        }
    }
}

//Essa funlçao tranformará o caracter em minusculo
void minusculaChar(char *ch){
    if(*ch >= 'A' && *ch <= 'Z'){
        *ch = *ch + 32;
    }
}

//essa função testa se os arquivos foram abertos corretamente
void testArq(FILE *arq){
    if(arq == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

}

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
            //agora ele irapercorre a lista de valores e pegar o valor na posição random
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
        code = busca(lista, mstr);
        fprintf(MensagemCodificada, "%d ", code);
}


//essa função vai decodificar a mensagem
void decoder(struct Lista *lista, int code, FILE *MensagemDecodificada){
    
}