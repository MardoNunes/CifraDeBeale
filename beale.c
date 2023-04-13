#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "libBeale.h"
#include "libLista.h"


//argc conta quantos argumentos estão sendo passados na entrada, incluindo o nome do programa
//argv é um vetor de strings que contém os argumentos passados na entrada
int main(int argc, char **argv){
    //estrutura
    struct Lista *lista = malloc(sizeof(struct Lista));
    lista->inicio = NULL;
    lista->fim = NULL;

    //arquivos
    FILE *LivroCifra;  //guarda as minhas chaves do livro cifra
    FILE *ArquivoDeChaves; //receberá a saida. O arquivo de chaves
    FILE *MensagemOriginal; //receberá a mensagem original
    FILE *MensagemCodificada; //receberá a mensagem codificada

    int nav;
    char str[1024];
    int pos = 0;
    

    nav = checkall(argc, argv);
    switch (nav)
    {
    case 1:{ //encoder
        
        
        //abrindo o arquivos de entrada
        LivroCifra = fopen("LivroCifra.txt", "r");
        ArquivoDeChaves = fopen("ArquivoDeChaves.txt", "w");
        MensagemOriginal = fopen("MensagemOriginal.txt", "r");
        MensagemCodificada = fopen("MensagemCodificada.txt", "w");
        
        
        //verrificando se os arquivos foram abertos corretamente
        testArq(LivroCifra);
        testArq(ArquivoDeChaves);
        testArq(MensagemOriginal);
        testArq(MensagemCodificada);

        //processo de leitura e estruturação:

        //le todas as linhas do arquivo paravra por palavra
        fscanf(LivroCifra, "%s", str); //fscanf para ler palavra por palavra
        while(!feof(LivroCifra)){
            minusculaStr(str); //deixo todos os caracteres em minusculo 
            enqueue(lista, str[0], pos);    //passo a chave e o valor para adicionar nas listas
            pos++; //inremento da qtd de palavras
            fscanf(LivroCifra, "%s", str);
        }

        //Processo de codificação:
        char mstr;
        //le o arquivo caracter por caracter
        mstr = fgetc(MensagemOriginal); //le o primeiro caractere
        while(mstr != EOF){
            minusculaChar(&mstr);
            encoder(lista, mstr, MensagemCodificada);
            mstr = fgetc(MensagemOriginal);
            
        }
        //fecha o arquivo
        fclose(LivroCifra);
        imprimi(lista, ArquivoDeChaves);
        fclose(ArquivoDeChaves);
        fclose(MensagemOriginal);
        fclose(MensagemCodificada);
        dequeue(lista);

        break;
    }
    case 2:
        //decoder com arquivo chave

        //abrindo arquivos
        ArquivoDeChaves = fopen("ArquivoDeChaves.txt", "r");


        //verrificando se os arquivos foram abertos corretamente
        testArq(ArquivoDeChaves);


        //processo de leitura e estruturação:
        //vou ler o arquivo de chaves e adicionar na estrutura
        fscanf(ArquivoDeChaves, "%s", str); //fscanf para ler palavra por palavra
        while(!feof(ArquivoDeChaves)){
            if(str[0] >= 'a' && str[0] <= 'z')
                printf("Chave: %c\n", str[0]);
            else
                printf("Valores: %s\n", str);
            fscanf(ArquivoDeChaves, "%s", str);
        }

        //fecha o arquivo
        fclose(ArquivoDeChaves);
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