#ifndef _PDB_PARSER_H
#define _PDB_PARSER_H

/* Returns 0/1 if reading the files was successful/unsuccessful */
int pdb_parse(char* pdb_filename, char* itp_filename, float* lattice);

#endif
