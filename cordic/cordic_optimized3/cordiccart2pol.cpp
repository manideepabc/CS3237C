#include "cordiccart2pol.h"

data_t Kvalues[NO_ITER] = {1,	0.500000000000000,	0.250000000000000,	0.125000000000000,	0.0625000000000000,	0.0312500000000000,	0.0156250000000000,	0.00781250000000000,	0.00390625000000000,	0.00195312500000000,	0.000976562500000000,	0.000488281250000000,	0.000244140625000000,	0.000122070312500000,	6.10351562500000e-05,	3.05175781250000e-05, 1.525878906250000e-05, 7.629394531250000e-06, 3.814697265625000e-06, 1.907348632812500e-06};

data_t angles[NO_ITER] = {0.785398163397448,	0.463647609000806,	0.244978663126864,	0.124354994546761,	0.0624188099959574,	0.0312398334302683,	0.0156237286204768,	0.00781234106010111,	0.00390623013196697,	0.00195312251647882,	0.000976562189559320,	0.000488281211194898,	0.000244140620149362,	0.000122070311893670,	6.10351561742088e-05,	3.05175781155261e-05, 1.525878906131576e-05, 7.629394531101970e-06, 3.814697265606496e-06, 1.907348632810187e-06};


void cordiccart2pol(data_t x, data_t y, data_t * r,  data_t * theta)
{

	// Write your code here

	acc_t offset;
	coord_t x0,y0;
	offset = 0;

#pragma HLS pipeline II=1
	coord_t _x,_y;
	_x = (coord_t)x;
	_y = (coord_t)y;


	if(_x <= 0 && _y > 0){
		offset = 1.57;
		//x0 = (coord_t)y;
		//y0 = -(coord_t)x;
		x0 = _y;
		y0 = -_x;
	}
	else if(_x <= 0 && _y <= 0){
		offset = -1.57;
		//x0 = -(coord_t)y;
		//y0 = (coord_t)x;
		x0 = -_y;
		y0 = _x;
	}
	else{
		//x0 = (coord_t)x;
		//y0 = (coord_t)y;
		x0 = _x;
		y0 = _y;
	}

	ap_uint<4> i;
	ap_int<2> sigma;

	coord_t x_shift,y_shift;

	Calculation_Loop: for(i=0; i < NUM_ITER; i++){
		sigma = (y0 >= 0) ? -1 : 1;

		// Calculate x_shifts
		x_shift = sigma*(y0>>i);
		y_shift = sigma*(x0>>i);

		x0 = x0 - x_shift;
		y0 = y0 + y_shift;

		offset += -sigma*(acc_t)angles[i];
	}

	*r = 0.607*(data_t)x0;
	*theta = (data_t)offset;
}
