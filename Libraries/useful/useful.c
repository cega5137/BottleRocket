#include "useful.h"

///////////////////// BuildMatrix /////////////////
double** BuildMatrix(int Nrows, int Ncols) {

	int N;
	double** A = (double**) calloc(Nrows, sizeof(double*));
	
	A[0] = (double*)calloc(Nrows*Ncols,sizeof(double)); // Allocates Entire Matrix

	for (N = 1; N<Nrows;++N) {
		A[N] = A[N-1] + Ncols; // Appropriately Defines "Vector of pointers to Rows"
	}

	return A;

}

////////////////////// Linspace ///////////////////////////
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

/////////////////////////// max //////////////////////////
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

/////////////////////////// min //////////////////////////////
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

