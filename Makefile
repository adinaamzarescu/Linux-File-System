CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -g
OBJS= tema1.o create.o free_mem.o init.o list.o move.o paths.o remove.o

build: tema1
tema1: tema create free_mem init list move paths remove
	$(CC) $(OBJS) -o tema

create: create.c
	$(CC) $(CFLAGS) $^ -c

free_mem: free_mem.c
	$(CC) $(CFLAGS) $^ -c

init: init.c
	$(CC) $(CFLAGS) $^ -c

list: list.c
	$(CC) $(CFLAGS) $^ -c

move: move.c
	$(CC) $(CFLAGS) $^ -c

paths: paths.c
	$(CC) $(CFLAGS) $^ -c

remove: remove.c
	$(CC) $(CFLAGS) $^ -c

tema: tema1.c tema1.h
	$(CC) $(CFLAGS) $^ -c

clean:
	rm -f *.o tema tema1.h.gch

checker:
	python3 checker.py
	make clean
