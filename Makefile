CFLAGS = -Wall -g -std=c99 -c

objs = beale.o libBeale.o libLista.o libDecoder.o libEncoder.o

all: beale
	
beale: ${objs}

beale.o: beale.c libBeale.h libLista.h libDecoder.h libEncoder.h
	gcc ${CFLAGS} -c beale.c
libBeale.o: libBeale.c libBeale.h libLista.h
	gcc ${CFLAGS} -c libBeale.c
libLista.o: libLista.c libLista.h
	gcc ${CFLAGS} -c libLista.c
libDecoder.o: libDecoder.c libDecoder.h libLista.h
	gcc ${CFLAGS} -c libDecoder.c
libEncoder.o: libEncoder.c libEncoder.h libLista.h
	gcc ${CFLAGS} -c libEncoder.c
	

clean:
	rm -f beale ${objs} *~

purge: clean
	rm -f beale 