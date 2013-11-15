#include <stdio.h>
#include "parse.h"

int main() {
	char pdb_filename[] = "ortho_dimer.pdb";
	char itp_filename[] = "ortho_dimer.itp";
	float* lattice = NULL;
	int ret_val = pdb_parse(pdb_filename, itp_filename, lattice);
	printf("%d\n", ret_val);
	return 0;
}
