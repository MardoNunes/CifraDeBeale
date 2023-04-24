#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "libBeale.h"
#include "libLista.h"
#include "libDecoder.h"
#include "libEncoder.h"


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
    FILE *MensagemDecodificada; //receberá a mensagem decodificada

    int nav;
    
    

    nav = checkall(argc, argv);
    switch (nav)
    {
    case 1:{ //encoder
        
        char str[1024];
        int pos = 0;
        
        //abrindo o arquivos de entrada
        LivroCifra = fopen("LivroCifra.txt", "r");
        ArquivoDeChaves = fopen("ArquivoDeChaves.txt", "w+");
        MensagemOriginal = fopen("MensagemOriginal.txt", "r");
        MensagemCodificada = fopen("MensagemCodificada.txt", "w+");
        
        
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
            enqueue(lista, str[0], pos);    //passo a chave e o valor para a estrutura
            pos++; //inremento a posição
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

        imprimi(lista, ArquivoDeChaves);    //aqui é montado o arquivo de chaves!

        //liberando memoria
        fclose(LivroCifra);
        fclose(ArquivoDeChaves);
        fclose(MensagemOriginal);
        fclose(MensagemCodificada);
        dequeue(lista);

        break;
    }
    case 2: {
        //decoder com arquivo chave
        
        char str[1024];
        int valor = -1; //ira receber a conversão de str para int
        char chave; //ira receber a chave
        


        //abrindo arquivos
        ArquivoDeChaves = fopen("ArquivoDeChaves.txt", "r");
        MensagemCodificada = fopen("MensagemCodificada.txt", "r");
        MensagemDecodificada = fopen("MensagemDecodificada.txt", "w");
        
        //verrificando se os arquivos foram abertos corretamente
        testArq(ArquivoDeChaves);
        testArq(MensagemCodificada);
        testArq(MensagemDecodificada);

        //processo de leitura e estruturação:
        //vou ler o arquivo de chaves e adicionar na estrutura
        fscanf(ArquivoDeChaves, "%s", str); //fscanf para ler palavra por palavra
        while(!feof(ArquivoDeChaves)){
            
            //Jogando o arquivo de chaves na estrutura

            if(str[0] >= 'a' && str[0] <= 'z'){  //verefica se é uma chave, qunado é letra
                chave = str[0];
                
            }
            else if(str[0] >= '0' && str[0] <= '9' && str[1] == ':'){    //verefica se é uma chave, mas se é um numero
                chave = str[0];

            }
            else if((str[0] >= 33 && str[0] <= 47) || (str[0] >= 58 && str[0] <= 64) || (str[0] >= 91 && str[0] <= 96)){ //verefica se é uma chave, mas se é um caractere especial
                chave = str[0];
            }
            else{   //se não for uma chave, é um valor
                valor = atoi(str);    //cast para int
            }
            
            if(valor != -1){
               
                enqueue(lista, chave, valor);
                valor = -1;
            }
            fscanf(ArquivoDeChaves, "%s", str);
        }

            //Agora vou fazer a decodificação
            //le o arquivo palavra por palavra e busco na estrutura
            char mstr[1024];  //recebe o caractere
            int caracter;  //recebe o valor do caractere
            fscanf(MensagemCodificada, "%s", mstr);
            while(!feof(MensagemCodificada)){
                caracter = atoi(&mstr[0]);
                decoder(lista, caracter, MensagemDecodificada);
                fscanf(MensagemCodificada, "%s", mstr);
            }

        
        //liberando memoria
        fclose(ArquivoDeChaves);
        fclose(MensagemCodificada);
        fclose(MensagemDecodificada);
        dequeue(lista);
        break;
    }
    case 3:{
        //decoder com livro cifra
        
        char str[1024];
        int pos = 0;
        int caracter;
        char mstr[1024];
  

        //abridno arquivos
        LivroCifra = fopen("LivroCifra.txt", "r");
        MensagemCodificada = fopen("MensagemCodificada.txt", "r");
        MensagemDecodificada = fopen("MensagemDecodificada.txt", "w");

        //vereficando..
        testArq(LivroCifra);
        testArq(MensagemCodificada);
        testArq(MensagemDecodificada);


        //processo de leitura e estruturação:
        //vou pegar o que extraio do livro cifra e adicionar na estrutura
        fscanf(LivroCifra, "%s", str); //fscanf para ler palavra por palavra
        while(!feof(LivroCifra)){
            minusculaStr(str);   //deixo tudo minusculo
            enqueue(lista, str[0], pos);    //passo a chave e o valor para adicionar na estrutura
            pos++; //incremento da posição da palavra
            fscanf(LivroCifra, "%s", str);
        }

        //Agora vou fazer a decodificação
        fscanf(MensagemCodificada, "%s", mstr);
        while(!feof(MensagemCodificada)){
            caracter = atoi(&mstr[0]);
            decoder(lista, caracter, MensagemDecodificada);
            fscanf(MensagemCodificada, "%s", mstr);
            }

        //liberando memoria
        fclose(LivroCifra);
        fclose(MensagemCodificada);
        fclose(MensagemDecodificada);
        dequeue(lista);
        break;
    }
    default:

        error();
        break;
    }


    
    return 0;
}