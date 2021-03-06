#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//#include "dydt.h"


/* 
	*		RK45: Compute all of the constants for the two order methods
	* 	and returns the two different order methods and the error
	*		bewteen them.
	*
	* 	Input: time, y at that point, h (step); empty Y4, Y5, and error which 
	*		wil be rewriten after the function with the next time step.
	*
	*		Output: next time step with 4th and 5th order and the error between them.
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

void RK45(double t, double *y, double h, double *Y_4, double *Y_5, struct bottleparameters *C,double *error, int n_ode);

	
