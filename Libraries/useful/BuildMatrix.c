#include "BuildMatrix.h"

/* row major storage for a 2D matrix array */
double** BuildMatrix(int Nrows, int Ncols) {

	int N;
	double** A = (double**) calloc(Nrows, sizeof(double*));
	
	A[0] = (double*)calloc(Nrows*Ncols,sizeof(double)); // Allocates Entire Matrix

	for (N = 1; N<Nrows;++N) {
		A[N] = A[N-1] + Ncols; // Appropriately Defines "Vector of pointers to Rows"
	}

	return A;

}
