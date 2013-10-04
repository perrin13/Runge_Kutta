/**
 * fxnParse.cpp
 * John Brock
 * Date Created: 26 Aug 2010
 * Date Updated: 26 Aug 2010
 * Purpose: To use create and use functions w/ undetermined variables
**/

#include "fxnParse.h"

// Default Constructor
fxn::fxn(){}

// Constructor with FILE input
fxn::fxn(string s_input){
 func = s_input;
}

// Constructor with char * input
fxn::fxn(char *c_input){
 func = c_input;
}


// Finds, stores and counts variables in function string
void fxn::findVariables(){
 
}
