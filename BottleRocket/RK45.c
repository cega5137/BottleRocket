#include "RK45.h"

void RK45(double t, double *y, double h, double *Y_4, double *Y_5, struct bottleparameters *C,double *error, int n_ode) {

	///////////////// Setting the data structure
	double k1[n_ode], k2[n_ode], k3[n_ode], k4[n_ode], k5[n_ode], k6[n_ode], C[n_ode];
	int i;
	

	/* 
	*  Compute all of the constants for the two order methods
	*  and returns the two different order methods and the error
	*	 bewteen them.
	*/

	//////////////////// K1 /////////////////////////
	for (i = 0; i < n_ode; i++) {
		C[i] = 0;
	}

	dydt(t, y, C);

	for (i = 0; i < n_ode; i++) {
		k1[i] = h*y[i+n_ode];
	}
	
	///////////////////// K2 /////////////////////////
	for (i = 0; i < n_ode; i++) {
		C[i] = .25*k1[i];
	}

	dydt(t + .25*h, y, C);
	
	for (i = 0; i < n_ode; i++) {
		k2[i] = h*y[i+n_ode];
	}
	
	//////////////////// K3 //////////////////////
	for (i = 0; i < n_ode; i++) {	
		C[i] = (3/32)*k1[i] + (9/32)*k2[i];
	}

	dydt(t + (3/8)*h, y, C);

	for (i = 0; i < n_ode; i++) {
		k3[i] = h*y[i+n_ode];
	}

	//////////////////// K4 /////////////////////////////
	for (i = 0; i < n_ode; i++) {	
		C[i] = (1932/2197)*k1[i] - (7200/2197)*k2[i] + (7296/2197)*k3[i];
	}

	dydt(t + (12/13)*h, y, C);

	for (i = 0; i < n_ode; i++) {
		k4[i] = h*y[i+n_ode];
	}

	///////////////////////// K5 /////////////////////////
	for (i = 0; i < n_ode; i++) {	
		C[i] = (439/216)*k1[i] - 8*k2[i] +(3680/513)*k3[i] - (845/4104)*k4[i];
	}	

	dydt(t + h, y, C);
	
	for (i = 0; i < n_ode; i++) {
		k5[i] = h*y[i+n_ode];
	}
	/////////////////////////////K6 /////////////////////////////
	for (i = 0; i < n_ode; i++) {	
		C[i] = -(8/27)*k1[i] + 2*k2[i] - (3544/2565)*k3[i] + (1859/4104)*k4[i] - (11/40)*k5[i];
	}
	
	dydt(t + .5*h, y, C);
	
	for (i = 0; i < n_ode; i++) {	
		k6[i] = h*y[i+n_ode];
	}	

	//////////////////////////////// The two different order and the error between them ///////////////
	
	for (i = 0; i < n_ode; i++) {
	
		Y_4[i] = y[i] + (25/216)*k1[i] + (1408/2565)*k3[i] + (2197/4104)*k4[i] + (1/5)*k5[i];

		Y_5[i] = y[i] + (16/135)*k1[i] + (6656/12825)*k3[i] + (28561/56130)*k4[i] + (9/50)*k5[i] + (2/55)*k6[i];
	
		error[i] = abs(Y_5[i] - Y_4[i]);	
	
	}
	
	

}
