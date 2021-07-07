# c_basic2
first C curse, hw2 - Strings, Structures and Dynamic allocations.

In this exercise you must solve a system of linear equations.
The program will receive from the user the number of equations that the system includes, this value can be in the range 1-3.
Modified and Invalid Value Input Another message will be displayed and another input attempt will be made.
After the explanation, a string user must be received for each continuation, which must be analyzed according to the rules described below.

Each system of linear equations cannot represent using a coefficient matrix A, vector B solutions and vector disappear X.
The system may not have a single solution or no solution at all. - It should be warned
Equality input equation:
• The number of equations is equal to the number of disappearances in the system and therefore the coefficient matrix is necessarily quadratic.
• It can be assumed that the first input of the number of equations is an int integer
• The length of each equation should not exceed 80 characters
• As part of the equation receiver the user can tap spaces, these characters should be ignored.
• It can be assumed that the input of the equations will be correct:
  o A set of equations which contains one missing equation is x
  o A set of equations which contains two vanishing equations are x, y
  o A system of equations which contains three vanishing equations are x, y, z
  o No need to perform a string input test
• It can be assumed that the input of the equation will be as follows:
  o The left side of the equation contains the coefficients a, b, c and the variables x, y, z depending on the number of equations.
  o The right side of the equation will contain only the free limb d
  o The variables x, y, z will appear only as lowercase letters
  oThere will be no need to perform complex arithmetic operations
