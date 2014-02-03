/* vim: set ts=8 sts=2 sw=2 et: */
#include <stdio.h>
#include <stdlib.h>
#include "electrokinetics_pdb_parse.hpp"

int main() {
  char pdb_filename[] = "ortho_dimer.pdb";
  char itp_filename[] = "ortho_dimer.itp";
  EK_parameters ek_parameters = {0.0625,160,160,160};

  float* charge_lattice = (float*) calloc( ek_parameters.dim_x * ek_parameters.dim_y * ek_parameters.dim_z, sizeof(float));
  int* boundary_lattice = (int*) calloc( ek_parameters.dim_x * ek_parameters.dim_y * ek_parameters.dim_z, sizeof(int));

  pdb_parse(pdb_filename, itp_filename, charge_lattice, boundary_lattice, &ek_parameters, 0);

  print_charge_field("charge_field.vtk", charge_lattice, &ek_parameters);
  print_boundary_lattice("boundary_lattice.vtk", boundary_lattice, &ek_parameters);
  return 0;
}
