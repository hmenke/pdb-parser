CC = clang++
CFLAGS = -Wall -Wextra -O3
LDFLAGS= -lm

test: test.o electrokinetics_pdb_parse.o
	$(CC) -o test test.o electrokinetics_pdb_parse.o $(LDFLAGS)

electrokinetics_pdb_parse.o: electrokinetics_pdb_parse.cpp electrokinetics_pdb_parse.hpp
	$(CC) -c $(CFLAGS) -o electrokinetics_pdb_parse.o electrokinetics_pdb_parse.cpp

test.o: test.cpp
	$(CC) -c $(CFLAGS) -o test.o test.cpp

debug: test.o electrokinetics_pdb_parse.o
	CFLAGS='-Wall -Wextra -O0 -ggdb'
	$(CC) -o test test.o electrokinetics_pdb_parse.o $(LDFLAGS)

.PHONY: clean
clean:
	$(RM) test.o electrokinetics_pdb_parse.o test
