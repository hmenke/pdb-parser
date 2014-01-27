#ifndef _PDB_PARSER_H
#define _PDB_PARSER_H

typedef struct {
  float agrid;
  int dim_x;
  int dim_y;
  int dim_z;
} lattice_parameters;

/* Returns 0/1 if reading the files was successful/unsuccessful */
int pdb_parse(char* pdb_filename, char* itp_filename, float* charge_lattice, int* boundary_lattice, lattice_parameters* ek_parameters, int indices_only);

int print_charge_field(char* filename, float* charge_lattice, lattice_parameters* ek_parameters);

int print_boundary_lattice(char* filename, int* boundary_lattice, lattice_parameters* ek_parameters);


#endif
