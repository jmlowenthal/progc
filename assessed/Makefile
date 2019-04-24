CC=gcc -std=c99 -Wall --pedantic

client: client1.c
	$(CC) -o client client1.c

server: server1.c
	$(CC) -o server server1.c

summary: summary.c
	$(CC) -o summary summary.c

extract: extract.c
	$(CC) -o extract extract.c

all: client server summary extract

.DEFAULT_GOAL := all
