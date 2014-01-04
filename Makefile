CC = clang
CFLAGS = -Wall -Wextra -O3 --std=c99
LDFLAGS= -lm

test: test.o parse.o
	$(CC) $(LDFLAGS) -o test test.o parse.o

parse.o: parse.c parse.h
	$(CC) -c $(CFLAGS) -o parse.o parse.c

test.o: test.c
	$(CC) -c $(CFLAGS) -o test.o test.c

debug: test.o parse.o
	CFLAGS='-Wall -Wextra -O0 -ggdb'
	$(CC) $(LDFLAGS) -o test test.o parse.o

.PHONY: clean
clean:
	$(RM) test.o parse.o test

compress: pdb_parser.tar.bz2

pdb_parser.tar.bz2: test.c parse.c parse.h Makefile
	tar -cjf pdb_parser.tar.bz2 parse.c parse.h test.c Makefile
