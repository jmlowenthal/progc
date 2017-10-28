CC=gcc -std=c99 -Wall --pedantic

client.o: client.c
	$(CC) -c client.c

client: client.o
	$(CC) -o client client.o

server.o: server.c
	$(CC) -c server.c

server: server.o
	$(CC) -o server server.o

all: client server

.DEFAULT_GOAL := all
