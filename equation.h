#ifndef _E
#define _E

typedef struct {
	int count;
	float* A;
	float B;

} Equation;

Equation* getEquation(int i, int num);
int getCount(char* str);
void setCoefficients(Equation* eq, char* str);
void getFreeNumber(char* cpstr, Equation* eq);

#endif
