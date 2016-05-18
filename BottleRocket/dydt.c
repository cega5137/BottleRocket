#include"dydt.h"


void dydt(double t, double *y, struct C) {


// ************ Data structre ******************* //
double volume, current_mass, velocity, theta, xpos, ypos, zpos;
double *v, *rel_velocity, *heading;
double temperature_e, rho_air, temperature, air_P_critical, temperature_exit;
double rho_air_exit, M_e, exitvelair, V_exit, pressure, final_pressure, mass_air;
double dvoldt, dmdt, dVdt, dtheta_dt, dXdt, dYdt, dZdt;
double F_drag,F_thrust, pressure_change, current_pressure;
heading = calloc(3,sizeof(double));
rel_velocity = calloc(3,sizeof(double));
v = calloc(3,sizeof(double));

// ***************** conditions ******************** //
	volume        = y[0];	
	current_mass  = y[1];
	velocity      = y[2];
	theta         = y[3];
	xpos          = y[4];
	ypos          = y[5];
	zpos          = y[6];

	if (current_mass < C.dry_mass) {
  	current_mass = C.dry_mass;
	}

	v[0] = velocity * cos(theta);
	v[1] = 0;
	v[2] = velocity * sin(theta);

	memcpy(rel_velocity,v,3);
	cblas_daxpy(3,-1,C.velocity_wind,1,rel_velocity,1);
	velocity = cblas_dnrm2(3,rel_velocity,1);    // blas
	if ( velocity == 0 ) {
  	heading[0] = cos(theta);
 	 	heading[1] = 0;
  	heading[2] = sin(theta);
	}

	else {
  	cblas_daxpy(3,1/velocity,rel_velocity,1,heading,1); // blas
	}

	F_drag = .5*C.rho_air_atm*pow(velocity,2)*C.c_D*C.area_bottle;

/*
 ***************************************************************
 ****************************** Phase 1 ************************
 ***************************************************************
*/
	if (current_mass > (C.mass_air_initial + C.dry_mass) ) {

		current_pressure = C.pressure_initial * pow(C.volume_air_initial/volume,C.gamma);
		pressure_change  = current_pressure - C.amb_pressure;
		if (pressure_change <= 0) {
			pressure_change = 0;
		}

		F_thrust = 2*C.c_d*pressure_change*C.area_exit;
		dvoldt   = C.c_d*C.area_throat*sqrt(2*(pressure_change)/C.rho_water);
		V_exit   = sqrt(2*pressure/C.rho_water);
		dmdt     = -C.c_d*C.area_throat*C.rho_water*V_exit;

		final_pressure = current_pressure;

	}

/*
 ***************************************************************
 ****************************** Phase 2 ************************
 ***************************************************************
*/
	else if (current_pressure <= C.Pend && current_pressure > C.amb_pressure ) {

		mass_air = current_pressure*volume/C.R/C.Tend;

		current_pressure = C.Pend*pow(mass_air/C.mass_air_initial,C.gamma);

		air_P_critical = current_pressure * pow(2/(C.gamma+1),C.gamma/(C.gamma-1));

		rho_air = mass_air/C.volume_initial;

		temperature = C.amb_Temperature*pow(rho_air/C.rho_air_atm,C.gamma-1);

		if (air_P_critical > C.amb_pressure) { 
			temperature_exit = (2/(C.gamma+1))*temperature;
			rho_air_exit = current_pressure/(temperature_exit * C.R);
			exitvelair = sqrt(C.gamma*C.R*temperature_exit);
		}

		else {
			M_e = sqrt((pow(current_pressure/C.amb_pressure,(C.gamma-1)/C.gamma) - 1)*(2/(C.gamma-1)));
      temperature_e = temperature*(1+((C.gamma-1)/2)*(pow(M_e,2)));
      rho_air_exit = C.amb_pressure/(C.R*temperature_e);
      exitvelair = M_e*sqrt(C.gamma*C.R*temperature_e);
		}
	
		dmdt = -C.c_d*rho_air_exit*C.area_bottle*exitvelair;
		pressure_change = current_pressure - C.amb_pressure;
		if (pressure_change <= 0 ) {
			pressure_change = 0;
		}

		dvoldt = 0;
		F_thrust = dmdt*velocity + pressure_change * C.area_throat;
	}

/*
 ***************************************************************
 ****************************** Phase 3 ************************
 ***************************************************************
*/
	else {

		F_thrust = 0;
		dmdt     = 0;
		dvoldt   = 0;
	}

/* 
 ********************* Attitude of the bottlerocket ************
*/

	if (zpos < C.L_pad*sin(C.theta_initial) && xpos < C.L_pad*cos(C.theta_initial) ) {
		
		dtheta_dt = 0;
		dVdt = F_thrust/current_mass - F_drag/current_mass - C.g*sin(theta) - C.nu*C.g*cos(theta);
	}

	else {

		dtheta_dt = -(C.g/velocity)*cos(theta);
		dVdt = F_thrust/current_mass - F_drag/current_mass - C.g*sin(theta);
	}

	dXdt = velocity * heading[0];
	dYdt = velocity * heading[1];
	dZdt = velocity * heading[2];

// *************************** Primes ******************************** \\

	y[7] = dvoldt;
	y[8] = dmdt;
	y[9] = dVdt;
	y[10] = dtheta_dt;
	y[11] = dXdt;
	y[12] = dYdt;
	y[13] = dZdt;

}
