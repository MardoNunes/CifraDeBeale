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
void minuscula(char *str){
    int i;
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + 32;
        }
    }
}

//essa função testa se os arquivos foram abertos corretamente
void testArq(FILE *arq){
    if(arq == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

}

//essa função ira buscar o caracter na lista e codificar
int busca(struct Lista *lista, char chave){
    struct nodoDuplo *aux = lista->inicio;
    int value;
    while(aux != NULL){ //percorre a lista de chaves
        if(aux->chave == chave){    //se achar a chave, adiciono em value e retorno ess valor
            struct nodo *aux2 = aux->valor; //O erro está aui, esse declaração!!
            value = aux2->valor;    //adiciona o valor na variavel value
            aux2 = aux2->prox;  //vai para o proximo valor
            
            if(aux2 == NULL){
                aux2 = aux->valor;  //se o proximo valor for nulo, ele volta para o primeiro valor
            }
            return value;
        }
        aux = aux->prox;
    }
    printf("Caracter não encontrado!\n");
    return -1;
}


//essa função vai separar cada caracter da string e codificar
void encoder(struct Lista *lista, char *mstr){
    char aux;
    int code;
    for(int i = 0; i < strlen(mstr); i++){
        aux = mstr[i];
        code = busca(lista, aux);
        if(code == -1){
            error();
            exit(1);
        }
        printf("%d ", code);
    }
    printf("-1 ");
}
