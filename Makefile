CC = clang
CFLAGS = -Wall -Wextra -O3 --std=c99

all: test.o parse.o
	$(CC) -o test test.o parse.o

ParticleGroup.o: parse.c parse.h
	$(CC) -c $(CFLAGS) -o parse.o parse.c

test.o: test.c
	$(CC) -c $(CFLAGS) -o test.o test.c

debug: test.o parse.o
	CFLAGS='-Wall -Wextra -O0 -ggdb'
	$(CC) -o test test.o parse.o

.PHONY : clean
clean:
	$(RM) test.o parse.o test

compress: test.cpp parse.c parse.h Makefile
	tar -cjf pdb_parser.tar.bz2 parse.c parse.h test.c Makefile
