//Koral nataf 208726257
//and
//Gal or 316083690
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "equation.h"
#include "allEquations.h"
#include "solver.h"
#include "general.h"

int main() {

	int number;
	printf("Number of equations: (1-3): ");
	scanf("%d", &number);
	getchar();
	while (number < 1 || number > 3) {
		printf(
				"wrong input! Number of equations must be between 1-3!\n please try again..\nNumber of equations: (1-3): ");
		scanf("%d", &number);
		getchar();
	}
	AllEquations* ae = (AllEquations*) malloc(sizeof(AllEquations));
	ae->count = number;
	ae->eqArr = (Equation**) malloc(number * sizeof(Equation*));

	for (int i = 0; i < number; i++) {
		ae->eqArr[i] = getEquation(i + 1, number);
	}
	Solver* solver = (Solver*) malloc(sizeof(Solver));
	convertToSolver(ae, solver);
	printMatrix(solver->A_Mat, solver->count);

	printf("\nMatrix A determinant = %.3f \n\n", solver->Detrmin);
	printArray(solver->B_Vec, solver->count);
	checkSol(solver);
	freeAllEquations(ae);
	freeSolver(solver);



}
