CC = clang
CFLAGS = -Wall -Wextra -O3 --std=c99
LDFLAGS= -lm

test: test.o electrokinetics_pdb_parse.o
	$(CC) $(LDFLAGS) -o test test.o electrokinetics_pdb_parse.o

electrokinetics_pdb_parse.o: electrokinetics_pdb_parse.c electrokinetics_pdb_parse.h
	$(CC) -c $(CFLAGS) -o electrokinetics_pdb_parse.o electrokinetics_pdb_parse.c

test.o: test.c
	$(CC) -c $(CFLAGS) -o test.o test.c

debug: test.o electrokinetics_pdb_parse.o
	CFLAGS='-Wall -Wextra -O0 -ggdb'
	$(CC) $(LDFLAGS) -o test test.o electrokinetics_pdb_parse.o

.PHONY: clean
clean:
	$(RM) test.o electrokinetics_pdb_parse.o test

compress: electrokinetics_pdb_parser.tar.bz2

electrokinetics_pdb_parser.tar.bz2: test.c electrokinetics_pdb_parse.c electrokinetics_pdb_parse.h Makefile
	tar -cjf electrokinetics_pdb_parser.tar.bz2 electrokinetics_pdb_parse.c electrokinetics_pdb_parse.h test.c Makefile
