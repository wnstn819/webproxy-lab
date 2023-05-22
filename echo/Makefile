# Makefile for Proxy Lab 
#
# You may modify this file any way you like (except for the handin
# rule). You instructor will type "make" on your specific Makefile to
# build your proxy from sources.

CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -lpthread
SOBJS = echoserveri.o echo.o csapp.o
COBJS = echoclient.o csapp.o


all: echo echoclient echoserveri

serveron : echoserveri 
	./echoserveri 15123
clienton : echoclient 
	./echoclient localhost 15123

csapp : csapp.c csapp.h
	$(CC) $(CFLAGS) -c csapp.c

echo : echo.c csapp.h
	$(CC) $(CFLAGS) -c echo.c

echoclient : ${COBJS}
	$(CC) $(CFLAGS) -o echoclient ${COBJS} $(LDFLAGS)

echoserveri : ${SOBJS}
	$(CC) $(CFLAGS) -o echoserveri ${SOBJS} $(LDFLAGS)

clean:
	rm -f *~ *.o proxy core *.tar *.zip *.gzip *.bzip *.gz echo echoclient echoserveri
