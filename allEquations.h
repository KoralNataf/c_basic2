#ifndef _AE
#define _AE

#include "equation.h"
#include "solver.h"
typedef struct {
	int count;
	Equation** eqArr;

} AllEquations;

void convertToSolver(const AllEquations* ae, Solver* solver);
void convertMatrix(const AllEquations* ae, Solver* solver);
void copyBvec(const AllEquations* ae, Solver* solver);
void freeAllEquations(AllEquations* ae);

#endif
