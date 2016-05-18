#include "ODE45.h"

void ODE45(double tmin, double tmax, double *y, struct *C,double tol, int n_ode) {

	double t,n;
	double Y4[n_ode], Y5[n_ode], eps[n_ode];	
	double h, kappa;
	int ii,jj;
	
	kappa = .5;

	while (t < tmax) {
		h = 5;
		RK45(t, y, h, Y4, Y5, eps);

		jj = max(eps,n_ode);
		
		while (eps[jj] > tol) {
			h = h*kappa*pow(eps[jj]/tol,1/(n_ode+1));
			RK45(t, y, h, Y4, Y5, eps, n_ode);
			jj = max(eps,n_ode);
		}	
		
		///// Can change this for memcpy ////
		for (ii = 0; ii < n_ode; ii++) {
			y[ii] = Y5[ii];
		}

		t =+ h;
	}

}
