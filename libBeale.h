/*
Biblioteca que contém as funções de checagem 
de argumento para o problema da cifra de Beale

Criado por: 
    Madoqueu F. Nunes
    27/03/2023


*/

#ifndef __LIBBEALE__
#define __LIBBEALE__


//Essa função irá printar a mensagem de erro
void error();

//Essa função ira checar se o numero de agurmentos passados é valido
//E se tais argumentos estão corretos
int checkall(int argc, char **argv);

#endif