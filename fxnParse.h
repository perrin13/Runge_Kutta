/**
 * fxnParse.h
 * John Brock
 * Date Created: 26 Aug 2010
 * Date Updated: 26 Aug 2010
 * Purpose: This file holds the specifications for a class that
 *		handles mathematical functions
 * Currently Supported Functions:
 *
**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

class fxn{
 public:
  //Constructors
  fxn();
  fxn(char *);
  fxn(string);

  // Destructors
  ~fxn();

  // Functions
  void fxnPrint();
  void fxnRun();  
  void fxnRun(double *);
  
 private:
  // Class specific variables
  string func; // contains the string representing the function
  int num;   // number of variables
  char *variables;  // list of variables

  // Background Functions
  void findVariables();
  

}
