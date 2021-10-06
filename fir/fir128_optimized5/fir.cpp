/*
	Filename: fir.cpp
		FIR lab wirtten for WES/CSE237C class at UCSD.
		Match filter
	INPUT:
		x: signal (chirp)

	OUTPUT:
		y: filtered output

*/

#include "fir.h"

void fir (
  data_t *y,
  data_t x
  )
{

	coef_t c[N] = {10, 11, 11, 8, 3, -3, -8, -11, -11, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -11, -11, -8, -3, 3, 8, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 8, 3, -3, -8, -11, -11, -10, -10, -10, -10, -10, -10, -10, -10, -11, -11, -8, -3, 3, 8, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 8, 3, -3, -8, -11, -11, -10, -10, -10, -10, -10, -10, -10, -10, -11, -11, -8, -3, 3, 8, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
	
	// Write your code here
	static data8_t shift_reg[N];
	//#pragma HLS BIND_STORAGE variable=shift_reg type=ram_2p impl=bram
	//#pragma HLS array_partition variable=shift_reg block factor = 16
	#pragma HLS array_partition variable=shift_reg complete
	acc_t acc;
	data8_t data;
	int i;

	acc=0;
	Shift_Loop: for (i=N-1;i>0;i--) {
	#pragma HLS UNROLL
	//#pragma HLS pipeline off
		shift_reg[i] = shift_reg[i-1];
    }
	shift_reg[0] = x;

	Accum_Loop: for(i=N-1;i>=0;i--){
	#pragma HLS UNROLL
		acc+=shift_reg[i]*c[i];
	}

  *y=acc;
}


