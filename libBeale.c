#include <stdio.h>
#include <stdlib.h>
#include "libBeale.h"


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
    

