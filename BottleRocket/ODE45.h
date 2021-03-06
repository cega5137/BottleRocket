#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
//#include "RK45.h"

/*
 *	ODE45: Numerical integrator with a adaptive step-size
 *	takes the min and max step size with the initial conditions 
 *	in a vector and the minimum tolerance.
 *
 *	Inputs: starting time and end time, y as a vector with the
 *	IC, the vector needs to be twice as big. The tolerance 
 *	require.
 *
 *	Output: The initial conditions will be rewriten with the finals
 *	number.
*/

/*
struct bottleparameters {
	double gamma; 
	double amb_pressure; 
	double R;
	double mass_initial;
	double L_pad; 
	double nu;
	double pressure_initial;
	double mass_water_initial; 
	double volume_initial;
	double rho_water;
	double area_exit;
	double g;
	double area_bottle;
	double c_D;
	double *velocity_wind; 
	double c_d;
	double area_throat; 
	double mass_air_initial;
	double dry_mass;
	double rho_air_atm; 
	double m_air_F;
	double amb_Temperature; 
	double theta_initial;
	double Pend;
	double Tend;
	double volume_air_initial; 
};
*/

void ODE45(double tmin, double tmax, double *y, struct *C, double tol, int n_ode);






