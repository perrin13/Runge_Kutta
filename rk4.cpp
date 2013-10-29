/** 
 * rk4.cpp
 * By: John Brock
 * Created: 08/25/2010
 * Modified:11/14/2010
 * Purpose: This file implements the rk4 class which solves
 *		coupled differential equations.
**/

#include "rk4.h"

rk4::rk4(){

}

rk4::rk4(FILE *in){
 fParse(in);
}

rk4::~rk4(){
}

void rk4::fParse(FILE *in){
 int i;
 string hold;
 n = getint(in);
 variables = new string[n + 1];
 equations = ((fxn **) new int[n]);
 iv = new double[n + 1];
 variables[0] = getstring(in);
 
 for(i = 1; i < n + 1; i++){
  variables[i] = getstring(in);
  // cout << variables[i] << endl;
 }
  
 for(i = 1; i < n + 1; i++){
  iv[i] = getdouble(in);
 }
 a = getdouble(in);
 b = getdouble(in);
 iv[0] = a;
 
 p = getint(in);
 h = (b-a)/p;
 for(i = 0; i < n; i++){
   hold = getstring(in);
   equations[i] = new fxn(hold);
   //cout << "Noob" << endl;
   equations[i]->fxnVars(variables, n+1);
   cout << equations[i]->fxnPrint() << endl;
 }

}

void rk4::solve(){
 out = fopen("rk4.dat","w");
 char c[256];
 double *prog = new double[n + 1]; 
 int i, j;
 
 for(i = 0; i < n+1; i++){
  prog[i] = iv[i];
 }
 strcpy(c, "# This file is called rk4.dat\n# Function data\n# X	Y\n");
 fwrite((void *) c, sizeof(char), 52, out);
 
 for(i = 0; i < p; i++){
  prog = pSolve(prog);
  
  fprintf(out, "\n%lf", prog[0]);
  for(j = 0; j < n; j++){
   fprintf(out, "	%lf", prog[j+1]);
  }
  
  prog[0] = prog[0] + h;
 }

 fclose(out);
}

double *rk4::pSolve(double *dod) {
 double k1[n];
 double k2[n];
 double k3[n];
 double k4[n]; 
 double y2;
 int i;
 double *dd = new double[n+1]; // Input holder
 
 for(i = 0; i < n+1; i++){
  dd[i] = dod[i];
 }
 
 for(i = 0; i < n; i++){
  k1[i] = equations[i]->evaluate(dd);
 }
 
 dd[0] = dod[0] + 0.5*h;
 for(i = 0; i < n; i++){
  dd[i+1] = dod[i+1] + 0.5*h*k1[i];
 }
 
 for(i = 0; i < n; i++){
  k2[i] = equations[i]->evaluate(dd);
 }

 dd[0] = dod[0] + 0.5*h;
 for(i = 0; i < n; i++){
  dd[i+1] = dod[i+1] + 0.5*h*k2[i];
 }

 for(i = 0; i < n; i++){
  k3[i] = equations[i]->evaluate(dd);
 }
 
 dd[0] = dod[0] + h;
 for(i = 0; i < n; i++){
  dd[i+1] = dod[i+1] + h*k3[i];
 }
 
 for(i = 0; i < n; i++){
  k4[i] = equations[i]->evaluate(dd);
 }
 
 for(i = 0; i < n; i++){
  dod[i+1] = dod[i+1] + (1.0/6)*(k1[i] + 2*k2[i] + 2*k3[i] + k4[i])*h;
 }
 
 delete(dd);
 return dod;
}
