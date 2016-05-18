#include<math.h>
#include<cblas.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

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

void dydt(double t, double *y, struct *C);
