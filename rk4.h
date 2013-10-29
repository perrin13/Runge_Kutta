/** 
 * rk4.h
 * John Brock
 * Date Created: 14 Nov 2010
 * Date Updated: 14 Nov 2010
 * Purpose: This file holds the specifications for a class that solves
 *		coupled differential equations via the Runge Kutta 4 
 *		method.
**/

#include "fxnParse.h"
#include "getnum.h"

class rk4{
 public:
 // Constructors
 rk4();
 rk4(FILE *);
 
 // Destructors
 ~rk4();
 
 // Functions
 void solve();

 private:
 // Class specific variables
 fxn **equations; // equations to be solved
 string *variables; // variables in the equations
 int n;	    // Number of equations
 double a;  // bottom of range
 double b;  // top of the range
 int p;	    // Number of partitions
 double h;  // Width of partitions
 double *iv; // initial values for variables
 FILE *out;  // file pointer for output
 
 double *pSolve(double *);
 void fParse(FILE *in);
};

