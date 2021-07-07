#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "solver.h"

float calcDet(float** matA, int num) // This function is to find the determinant value of matrix . . .
{
	float det = 0;
	if (num == 1)
		return matA[0][0];
	else if (num == 2)
		det = (matA[0][0] * matA[1][1]) - (matA[0][1] * matA[1][0]);
	else if (num == 3) {
		float x = (matA[1][1] * matA[2][2]) - (matA[2][1] * matA[1][2]);
		float y = (matA[1][0] * matA[2][2]) - (matA[2][0] * matA[1][2]);
		float z = (matA[1][0] * matA[2][1]) - (matA[2][0] * matA[1][1]);

		det = (matA[0][0] * x) - (matA[0][1] * y) + (matA[0][2] * z);
		return det;
	}
	return det;

}

void checkSol(Solver* solver) {
	solver->X_Vec = (float*) calloc(solver->count, sizeof(float));
	if (solver->Detrmin == 0)
		printf("There is no single solution for that system of equations...\n");
	else {
		if (solver->count == 1)
			getSol1x1(solver);
		else if (solver->count == 2)
			getSol2x2(solver);
		else if (solver->count == 3)
			getSol3x3(solver);
	}
}

void getSol1x1(Solver* solver) {//solution for 1x1
	solver->X_Vec[0] = solver->B_Vec[0] / solver->A_Mat[0][0];
	printf("Vector x=\n		%.3f", solver->X_Vec[0]);

}

void getSol2x2(Solver* solver) {//solution for 2x2
	// _____ find matrix inversion ________

	float inv[2][2];
	inv[0][0] = solver->A_Mat[1][1] / solver->Detrmin;
	inv[0][1] = -solver->A_Mat[0][1] / solver->Detrmin;
	inv[1][0] = -solver->A_Mat[1][0] / solver->Detrmin;
	inv[1][1] = solver->A_Mat[0][0] / solver->Detrmin;

	// _____ inversion * vector B = solution. ________

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			solver->X_Vec[i] += inv[i][j] * solver->B_Vec[j];

	printf("Vector X = \n");
	printf("      x = %.3f\n", solver->X_Vec[0]);
	printf("      y = %.3f\n", solver->X_Vec[1]);

}

void getSol3x3(Solver* solver) {//solution for 3x3
	// _____ find matrix inversion ________
	float inv[3][3];
	float** a = solver->A_Mat;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			inv[j][i] =
					((a[(i + 1) % 3][(j + 1) % 3] * a[(i + 2) % 3][(j + 2) % 3])
							- (a[(i + 1) % 3][(j + 2) % 3]
									* a[(i + 2) % 3][(j + 1) % 3]))
							/ solver->Detrmin;
	}
	// _____ inversion * vector B = solution. ________

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			solver->X_Vec[i] += inv[i][j] * solver->B_Vec[j];

	printf("Vector X = \n");
	printf("	x = %.3f\n", solver->X_Vec[0]);
	printf("	y = %.3f\n", solver->X_Vec[1]);
	printf("	z = %.3f\n", solver->X_Vec[2]);

}

void freeSolver(Solver* solver) {//free solver
	free(solver->A_Mat);
	free(solver->B_Vec);
	free(solver->X_Vec);
	free(solver);
}
