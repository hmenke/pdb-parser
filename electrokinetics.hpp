/* vim: set ts=8 sts=2 sw=2 et: */
#ifndef _ELECTROKINETICS_H
#define _ELECTROKINETICS_H

typedef struct {
  float agrid;
  unsigned int dim_x;
  unsigned int dim_y;
  unsigned int dim_z;
} EK_parameters;

extern EK_parameters ek_parameters;

#endif /* ELECTROKINETICS_H */
