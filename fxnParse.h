/**
 * fxnParse.h
 * John Brock
 * Date Created: 26 Aug 2010
 * Date Updated: 31 Oct 2010
 * Purpose: This file holds the specifications for a class that
 *		handles mathematical functions
 * Currently Supported Functions:
 *
**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <locale>
#include <sstream>
using namespace std;
#include "tree.h"

class fxn{
 public:
  //Constructors
  fxn();
  fxn(char *);
  fxn(string str);

  // Destructors
  ~fxn();

  // Functions
  string fxnPrint();
  double evaluate();
  double evaluate(double *);
  int numVar();
  void fxnVars(string *, int);
 private:
  // Class specific variables
  tree *function; // Points to the tree containing the function  
  int num;   // number of variables
  double *x; // Pointer to variables
  string *variables; // Pointer to variables string

  // Background Functions
  void parseVar();
  int varHelp(int, string *); 
  string parseStr(string);
  string printHelp(string str, int i);
  double evalHelp();
};
  // Error Function
  double error_init(double,double);

   // Operation Functions
  double fxnCos(double,double);
  double fxnSin(double,double);
  double fxnTan(double,double);
  double fxnExp(double,double);
  double fxnPow(double,double);
  double fxnAdd(double,double);
  double fxnSub(double,double);
  double fxnMult(double,double);
  double fxnDiv(double,double);
  double fxnAcos(double,double);
  double fxnAsin(double,double);
  double fxnAtan(double,double);
  double fxnCosh(double,double);
  double fxnSinh(double,double);
  double fxnTanh(double,double);
  double fxnLn(double,double);
  double fxnPi(double,double);



