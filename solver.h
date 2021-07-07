#ifndef _S
#define _S

#include "equation.h"

typedef struct {
	int count;
	float** A_Mat;
	float* B_Vec;
	float Detrmin;
	float* X_Vec;

} Solver;

float calcDet(float** matA, int num);
void checkSol(Solver* solver);
void getSol1x1(Solver* solver);
void getSol2x2(Solver* solver);
void getSol3x3(Solver* solver);
void freeSolver(Solver* solver);

#endif
