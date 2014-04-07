/* vim: set ts=8 sts=2 sw=2 et: */
#include <stdio.h>
#include <stdlib.h>
#include "electrokinetics_pdb_parse.hpp"

EK_parameters ek_parameters;

int main() {
  char pdb_filename[] = "ortho_dimer.pdb";
  char itp_filename[] = "ortho_dimer.itp";
  ek_parameters.agrid = 0.0625;
  ek_parameters.dim_x = 160;
  ek_parameters.dim_y = 160;
  ek_parameters.dim_z = 160;

  pdb_parse(pdb_filename, itp_filename);

  print_charge_field((char*)"charge_field.vtk");
  print_boundary_lattice((char*)"boundary_lattice.vtk");
  return 0;
}
