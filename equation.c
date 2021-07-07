#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "equation.h"

#define SIZE 81

Equation* getEquation(int i, int num) {//get equation from user
	char str[SIZE];
	Equation* eq = (Equation*) malloc(sizeof(Equation));
	printf("Enter equation %d: ", i);
	fgets(str, sizeof(str), stdin);
	eq->count = num;
	setCoefficients(eq, str);
	return eq;

}

int getCount(char* str) {//ger the number of ** in equation
	int count = 0;
	char ch = '*';
	char* c = strchr(str, ch);
	while (c) {
		count++;
		c = strchr(c + 1, ch);
	}
	return count;

}

void setCoefficients(Equation* eq, char* str) { // get coefficients from equation
	float co;
	char** var = (char**) malloc(eq->count * sizeof(char*));
	char v; //x y z
	eq->A = (float*) calloc(eq->count, sizeof(float));

	int i = 0;
	char* d;
	char* cpstr = (char*) malloc(strlen(str) + 1);
	strcpy(cpstr, str);

	char* c = strtok(str, "+-");	//split the equation by delimiter'+-'

	while (c && i < getCount(cpstr)) {

		var[i] = c;
		sscanf(var[i], "%f %*c %c ", &co, &v);
		d = strstr(cpstr, c);
		if (*(d - 1) == '-')
			co *= (-1);

		if (toupper(v) == 'X')
			eq->A[0] = co;
		else if (toupper(v) == 'Y')
			eq->A[1] = co;
		else if (toupper(v) == 'Z')
			eq->A[2] = co;

		c = strtok(NULL, "-+");
		i++;
	}

	getFreeNumber(cpstr, eq);
	free(cpstr);
	free(var);

}

void getFreeNumber(char* cpstr, Equation* eq) {// get the free number
	char* temp = strtok(cpstr, "=");
	temp = strtok(NULL, "=");
	if(strstr(temp,"- ")){
	temp=strtok(temp,"- ");
	sscanf(temp, "%f", &(eq->B));
	eq->B*=(-1);
	}else
		sscanf(temp, "%f", &(eq->B));



}

