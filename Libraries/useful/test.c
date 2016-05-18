#include<stdio.h>
#include<stdlib.h>
#include "BuildMatrix.h"
#include<math.h>

/*
* This is a test function to test the function in the library
* useful.
*/
int main() {

	double *A, *B;
	int r,n;

	n = 3;
	A = calloc(n,sizeof(double));
	A[0] = 5;
	A[1] = 7;
	A[2] = 1;

	//r = max(A,n);
	B = calloc(n+1,sizeof(double));
	linspace(A[1],A[2],n,B);
	
	printf("B: %f \n",B[3]);
	printf("Done with the program \n");

	return 0;
}

void linspace(double imax, double imin, int n, double* A) {

	double delta;
	int i;
	//double *A;

	//// Compute the difference
	delta = (imax - imin)/(n);

	////// Initialize array ////
	//A = calloc(n,sizeof(double));

	
	for (i = 0; i <= n; i++) {
		
		A[i] = imin + i*delta;
		
	}
	//return A;
}


int max(double* A, int n ) {
	
	int i,m;

	m = 0;	
		
	for (i = 0; i < n; i++) {

		if (A[m] < A[i]) {
			m = i;
		}
	}
	return m;
}


int min(double* A, int n ) {
	
	int i,m;

	m = 0;	
		
	for (i = 0; i < n; i++) {

		if (A[m] > A[i]) {
			m = i;
		}
	}
	return m;
}

