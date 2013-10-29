#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

double add(double a, double b);
double (*pl)(double, double) = NULL;
double (*gg)(double,double) = NULL;

int main(){
 pl = &add;
 tree noob = tree(pl);
 noob.addLeft(3.0);
 noob.gtop();
 noob.addRight(2.0);
 noob.gtop();
 tree nub = tree(noob);

 gg = (double (*) (double,double))nub.position->getValue();
 double c = gg(((double *)nub.position->getLeft()->getValue())[0],((double *) nub.position->getRight()->getValue())[0]);
 printf("%f\n", c);

 return 0;
}

double add(double a, double b){
 return a+b;
}
