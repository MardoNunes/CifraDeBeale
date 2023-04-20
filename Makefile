CFLAGS = -Wall -g -std=c99 -c

objs = beale.o libBeale.o libLista.o

all: beale
	
beale: ${objs}

beale.o: beale.c libBeale.h libLista.h
	gcc ${CFLAGS} -c beale.c
libBeale.o: libBeale.c libBeale.h libLista.h
	gcc ${CFLAGS} -c libBeale.c
libLista.o: libLista.c libLista.h
	gcc ${CFLAGS} -c libLista.c
	

clean:
	rm -f beale ${objs} *~

purge: clean
	rm -f beale 