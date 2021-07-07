#include "general.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printArray(const float* arr, int size) {
	printf("Vector B =\n");
	for (int i = 0; i < size; i++) {
		printf("	%.3f\n", *(arr + i));
	}

}

void printMatrix(float** matrix, int size) {
	printf("\nMatrix A =\n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("	%.3f", matrix[i][j]);
		}
		printf("\n");
	}

}
