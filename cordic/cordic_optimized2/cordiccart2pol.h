#include <ap_int.h>
#include <ap_fixed.h>

#ifndef CORDICCART2POL_H
#define CORDICCART2POL_H

#define NO_ITER 20
#define NUM_ITER 14

typedef int   coef_t;
typedef float data_t;

typedef ap_fixed<17,3> acc_t;
typedef ap_fixed<16,3> coord_t;


void cordiccart2pol(data_t x, data_t y, data_t * r,  data_t * theta);

#endif
