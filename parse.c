#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse.h"

#define DEBUG

/* Replacements for bool variables */
int pdb_SUCCESS = 0;
int pdb_ERROR = 1;

/* structs might disappear in the future */
typedef struct {
	int i;
} pdb_MODEL;

typedef struct {
	int i;
	float x,y,z;
} pdb_ATOM;

typedef struct {
	int i;
	char type[2];
	float charge;
} itp_atoms;

typedef struct {
	char type[2];
	float sigma,epsilon;
} itp_atomtypes;

/* arrays to store info retreived from files */
int p; // number of particles
int* ids;
float* x = (float*) malloc(sizeof(float));
float* y = (float*) malloc(sizeof(float));
float* z = (float*) malloc(sizeof(float));
float* charge = (float*) malloc(sizeof(float));

int lj; // number of LJ parameters
float* sigma = (float*) malloc(sizeof(float));
float* epsilon = (float*) malloc(sizeof(float));

/* BEGIN CODE */

int pdb_parse_files(char* pdb_filename, char* itp_filename) {
	/*
	 * This routine parses the pdb- and itp-file to extract
	 * the relevant parameters. These are stored in arrays.
	 */

	// Parse pdb-file
	char pdb_line[256];
	FILE* pdb_file;
	if ((pdb_file = fopen(pdb_filename,"r")) == NULL) return pdb_ERROR;
#ifdef DEBUG
		printf("### Reading pdb-file \"%s\" ###\n",pdb_filename);
#endif	
	while (fgets(pdb_line, sizeof(pdb_line), pdb_file)) {
		if (strncmp(pdb_line,"MODEL",5) == 0) {
			// read the MODEL identifier
			pdb_MODEL m;
			sscanf(pdb_line,"MODEL %d",&m.i);
#ifdef DEBUG
			printf("MODEL m=%d\n", m.i);
#endif
		}
		if ( strncmp(pdb_line,"ATOM",4) == 0) {
			// read all ATOMs
			pdb_ATOM a;
			// See http://deposit.rcsb.org/adit/docs/pdb_atom_format.html#ATOM for the meaning of the format string
			sscanf(pdb_line,"ATOM %5d %*4s%*c%*3s%*c%*4d%*c %8f %8f %8f %*6f %*6f %*4s%*2s%*2s",&a.i,&a.x,&a.y,&a.z);
#ifdef DEBUG
			// Print all local variables
			printf("ATOM i=%d x=%f y=%f z=%f\n",a.i,a.x,a.y,a.z);
#endif
		}
	}
	fclose(pdb_file);

	// Parse itp-file
	char itp_line[256];
	FILE* itp_file;
	if ((itp_file = fopen(itp_filename,"r")) == NULL) return pdb_ERROR;
#ifdef DEBUG
		printf("### Reading itp-file \"%s\" ###\n",itp_filename);
#endif	
	while (fgets(itp_line, sizeof(itp_line), itp_file)) {
		// get section
		char section[256];
		sscanf(itp_line,"[ %s ]",section);
		// only read non-comment, non-section and non-empty lines
		// TODO: Handling of lines consiting whitespace only (e.g. '\t' and ' ')
		if (itp_line[0] != '[' && itp_line[0] != ';' && itp_line[0] != '\r' && itp_line[0] != '\n') {
			if (strcmp(section,"atoms") == 0) {
				// section [ atoms ]
				itp_atoms a;
				// FIXME: no source :( Reverse engineered from the itp-file
				sscanf(itp_line," %d %2s %*d %*s %*s %*d %f %*f ; %*s %*f",&a.i,a.type,&a.charge);
#ifdef DEBUG
				// Print all local variables
				printf("[ atoms ] i=%d type=%s charge=%f\n",a.i,a.type,a.charge);
#endif
			}
			if (strcmp(section,"atomtypes") == 0) {
				// section [ atomtypes ]
				itp_atomtypes a;
				// FIXME: no source :( Reverse engineered from the itp-file
				sscanf(itp_line," %2s %*s %*f %*f %*c %f %f ; %*f %*f",a.type,&a.sigma,&a.epsilon);
#ifdef DEBUG
				// Print all local variables
				printf("[ atomtypes ] name=%s sigma=%f epsilon=%f\n",a.type,a.sigma,a.epsilon);
#endif
			}
		}
	}
	fclose(itp_file);

	return pdb_SUCCESS;
}

int pdb_parse(char* pdb_filename, char* itp_filename, float* lattice) {
	/*
	 * This is the main parsing routine, which is visible to the outside
	 * through the header parse.h. It doesn't contain any logic and just
	 * deployes the input to the soubroutines.
	 */
	pdb_parse_files(pdb_filename, itp_filename);

	lattice = NULL;

	return pdb_SUCCESS;
}

