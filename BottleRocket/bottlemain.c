#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "ODE45.h"
//#include "RK45.h"
//#include "dydt.h"

/*
* This is the main code to run the and approximate where the bottle rocket will land
* With all of the specification of the bottlerocket.	
*/

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


int main(){

// Data struct//
double alt, P_valve, tol, initial_angle;
double *wind, *y0;
double tmin, tmax;

struct bottleparameters C;




C.velocity_wind = calloc(3,sizeof(double));

// Known
alt                 = 5064;                      // [ft]
P_valve             = 40;                        // [psi] 
initial_angle       = 45;                        // [deg]
C.amb_Temperature     = 68;                        // [F]
wind                = calloc(3,sizeof(double));  // [mph]
C.dry_mass            = 0.127;                     // [Kg]
C.mass_water_initial  = 0.999;                     // [Kg]
C.volume_initial      = 0.0023;                    // [m^3]
C.c_D                 = .2;                        // drag coefficient
C.nu                  = .1;                        // friction coefficient
C.rho_water           = 999.98;                    // [kg/m^3]
C.area_exit           = pow(0.0250/2,2)*M_PI;      // [m^2]
C.area_bottle         = (.0079);                   // [m^2]
C.L_pad               = .58;                       // [m]
C.c_d                 = .3;                        // discharge coefficient

// Constants 
C.R                   = 287;                       // J/kg/K
C.gamma               = 1.4;                       // for air
C.g                   = 9.80665;                   // m/s^2

// Conversions
C.theta_initial       = initial_angle*M_PI/180;
/*
C.velocity_wind       = convvel(wind);             // [mph] -> [m/s]
atmosisa(alt,T,a,C.amb_pressure,C.rho_air_atm);
C.pressure_initial    = convpres(P_valve,"psi","Pa") + C.amb_pressure;
C.mass_initial        = C.dry_mass + C.mass_water_initial;
C.area_throat           = C.area_exit;
volume_water          = C.mass_water_initial/C.rho_water;
C.volume_air_initial    = C.volume_initial - volume_water;
C.mass_air_initial      = C.volume_air_initial * C.rho_air_atm;
C.m_air_F               = C.rho_air_atm * C.volume_initial;
C.Pend                  = C.pressure_initial * pow(C.volume_air_initial/C.volume_initial,gamma);
C.Tend                  = C.amb_Temperature * pow(C.volume_air_initial/C.volume_initial,gamma-1);
*/

// Integration
y0                  = calloc(14,sizeof(double));
y0[0]               = C.volume_air_initial;
y0[1]               = C.mass_initial;
y0[3]               = C.theta_initial;
tmin                = 0;
tmax                = 10;
tol                 = .001;

//	ODE45(tmin, tmax, y0, &C, tol, 7);

	return 0;
}
