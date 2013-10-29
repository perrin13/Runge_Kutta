#include "fxnParse.h"

int main(){
 string func = "sin(pi(1,1),1)";
 string p_func;
 double d;
 double *dd = new double[2];
 cout << func << endl;

 fxn *noob = new fxn(func);
 p_func = noob->fxnPrint();
 cout << "This was in your tree: " << p_func << endl;
 
 dd[0] = 1;
 dd[1] = 3.14;
 d = noob->evaluate(dd);
 
 cout << "This is the fxn at x = 1: " << d << endl;
 return 0;
}
