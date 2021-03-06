/* vim: set ts=8 sts=2 sw=2 et: */
#ifndef _PDB_PARSER_H
#define _PDB_PARSER_H

#include "electrokinetics.hpp"

extern float* pdb_charge_lattice;
extern int* pdb_boundary_lattice;

/* Returns 0/1 if reading the files was successful/unsuccessful */
int pdb_parse(char* pdb_filename, char* itp_filename);

int print_charge_field(char* filename);

int print_boundary_lattice(char* filename);

#endif
