CC=gcc -g -Wall -pedantic
LNK=gcc

reverse.o: reverse.c
	$(CC) -c reverse.c

reverse: reverse.o
	$(LNK) -o reverse reverse.o

array_list.o: array_list.c array_list.h
	$(CC) -c array_list.c

linked_list.o: linked_list.c linked_list.h
	$(CC) -c linked_list.c

lists.o: lists.c linked_list.h
	$(CC) -c lists.c

lists: lists.o linked_list.o array_list.o
	$(LNK) -o lists lists.o linked_list.o array_list.o

all: reverse lists

clean:
	rm *.o lists reverse
