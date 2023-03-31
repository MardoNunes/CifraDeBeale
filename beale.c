#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "libBeale.h"



//argc conta quantos argumentos estão sendo passados na entrada, incluindo o nome do programa
//argv é um vetor de strings que contém os argumentos passados na entrada
int main(int argc, char **argv){
    FILE *arq;
    int nav;
    char str[1024];
    int pos = 0;
    

    nav = checkall(argc, argv);
    switch (nav)
    {
    case 1: //encoder
        
        
        //abrindo o arquivo de entrada
        
        arq = fopen("LivroCifra.txt", "r");
        
        
        //verrificando se o arquivo foi aberto corretamente
        if(arq == NULL){
            printf("Erro ao abrir o arquivo\n");
            exit(1);
        }

        //le todas as linhas do arquivo paravra por palavra
        fscanf(arq, "%s", str); //fscanf para ler palavra por palavra
        while(!feof(arq)){
            fprintf(stdout, "%c: %d\t\n", str[0], pos);  
            pos += strlen(str) + 1; //strlen conta o tamanho da string. +1 por causa do espaço
            fscanf(arq, "%s", str);
        }

      


        
        //fecha o arquivo
        fclose(arq);
        
        break;
    case 2:
        //decoder com arquivo chave
        
        break;
    case 3:
        //decoder com livro cifra
        
        break;
    default:
        error();
        break;
    }



    return 0;
}