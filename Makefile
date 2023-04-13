CFLAGS = -Wall -g -std=c99 # gerar "warnings" detalhados e infos de depuração
 
objs = beale.o libBeale.o libLista.o

# regra default (primeira regra)
all: beale
 
# regras de ligacao
beale:	$(objs)
 
# regras de compilação
beale.o:	beale.c
libargmain.o:	libBeale.c 
librb.o:	libLista.c
 
# remove arquivos temporários
clean:
	-rm -f $(objs) *~
 
# remove tudo o que não for o código-fonte
purge: clean
	-rm -f beale beale.o libBeale.o libLista.o