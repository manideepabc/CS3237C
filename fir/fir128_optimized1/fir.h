/*
	Filename: fir.h
		Header file
		FIR lab wirtten for WES/CSE237C class at UCSD.

*/
#include "ap_int.h"
#ifndef FIR_H_
#define FIR_H_

const int N=128;

typedef ap_int<5> coef_t;
typedef int	data_t;
typedef ap_int<8> data8_t;
typedef ap_int<20>	acc_t;

void fir (
  data_t *y,
  data_t x
  );

#endif
