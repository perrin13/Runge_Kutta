/**
 * fxnParse.cpp
 * John Brock
 * Date Created: 26 Aug 2010
 * Date Updated: Nov 01 2010
 * Purpose: To use create and use functions w/ undetermined variables
**/

#include "fxnParse.h"
typedef double (*runn)(double,double);

/**string variable[] = {"x", "y", "z", "NULL"};
runn varRun[] = 
    {&xRun, &xRun,&xRun,&error_init};**/

string fxnName[] = 
         {"cos","sin","tan","exp","^",
          "+","-","*","/","acos","asin",
          "atan","cosh","sinh","tanh","ln", "pi","NULL"};
runn fxnRun[] = 
   {&fxnCos, &fxnSin, &fxnTan, &fxnExp, 
    &fxnPow, &fxnAdd, &fxnSub, &fxnMult, 
    &fxnDiv, &fxnAcos, &fxnAsin, 
    &fxnAtan, &fxnCosh, &fxnSinh, 
    &fxnTanh, &fxnLn, &fxnPi, &error_init};


// Default Constructor
fxn::fxn(){}

// Constructor with FILE input
fxn::fxn(string s_input){
 function = new tree();
 num = 0;
 
 parseStr(s_input);
 parseVar();
 // cout << "pV" << endl;
}

// Constructor with char * input
fxn::fxn(char *c_input){
}

// Prints Function to string
string fxn::fxnPrint(){
 function->gtop();
 string str;
 int i = 0;
 
 str = printHelp(str, i);
  
 return str;
}

string fxn::printHelp(string str, int i){
 node *current = function->pos();
 node *left = current->getLeft();
 node *right = current->getRight();
 string str2 = str;
 string h;
 char c = current->gtype();
 int j = 0;
 void *value = current->getValue();
 runn funt = NULL;
 double d;
 
 if(c == 'F'){
   funt = ((runn) value);
   for(j = 0; fxnRun[j] != &error_init; j++){
    if(fxnRun[j] == funt) {
     break;
    }
   }
   
   str2 += fxnName[j];
   str2 += '(';
   j = -1;
   function->goTo(left);
   str2 = printHelp(str2, j);
   
   j = 0;
   if(i > 0)
    j = i;
   
   j++; 
   function->goTo(right);
   str2 = printHelp(str2, j);

 } else if(c == 'V'){
   h = *((string *) value);
   str2 += h;
   if(i > 0){
     for(j = 0; j < i; j++){
      str2 += ')';
     }
   }

 } else if(c == 'D'){
   d = ((double *)value) [0];
   string h= static_cast<ostringstream*>( &(ostringstream() << d) )->str();
   str2 += h;
   
   if(i > 0){
    for(j = 0; j < i; j++){
     str2 += ')';
    }
   }
 }
 
 if(i < 0){
   str2 += ',';
 }
 return str2;
}

// Changes variables to those indicated by string *
void fxn::fxnVars(string *sv, int nv){
  int i;
  // delete(x);
  // delete(variables);
  num = nv;
  x = new double[nv];
  variables = new string[nv];
 
  for(i = 0; i < nv; i++){
   variables[i] = sv[i];
   // cout << "sv: " << sv << " vars: " << variables[i] << endl;
  } 
  
  return;
}
// Parser converts strings to fxnTrees
string fxn::parseStr(string str){
 size_t found = 0;
 string value;
 string on = str.substr();
 int fxnNdx;
 node *left;
 node *right;
 node *current = function->pos();
 int i = 1;
 double d = 0;
 const char *s;
 runn funRun;
 string *vag;
 
 found = on.find_first_of("(),");
 
 while(on[found+i] == ')' || on[found+i] == '(' || on[found+i] == ','){
  i++; 
 }
 
 value = on.substr(0,found);
 on = str.substr(found+i);
 if(str[found] == '('){
  for(fxnNdx = 0; fxnName[fxnNdx].compare("NULL") != 0; fxnNdx++){
   if(value.compare(fxnName[fxnNdx]) == 0){
    break;
   }
  }

  current->getValue((void *)fxnRun[fxnNdx]);
  
  function->addLeft();
  on = parseStr(on);
  function->goTo(current);
  function->addRight();
  on = parseStr(on);
  function->goTo(current);
  
 } else {
  if(value[0] != 45 && (value[0] < 48 || value[0] > 57)){
   vag = new string(value);
   current->getValue((void *)vag);
   current->gtype('V');
   num++;
  } else {
   d = atof(value.c_str());
   current->getValue(d);
  }
 }
 
 return on;
}
 
// Sets up variable storage
void fxn::parseVar(){
 int i = 0;
 int j = 0;
 int k = 0;
 int m = 0;
 int n = 0;
 string *raw = new string[num];
 string *revised = new string[num];
 function->gtop();
 
 k = varHelp(k, raw);
 // cout << k << endl;
 if(k > 0){
  revised[0] = raw[0];
  m++;
  for(i = 1; i < k; i++){
   n = 0;
   for(j = 0; j < m; j++){ 
     if(raw[i].compare(revised[j]) == 0)
      break;
   }
   if(j == m){
    revised[m] = raw[i];
    m++;
   }
  }
  
  num = m;
  variables = new string[m];
  x = new double[m];
  for(i = 0; i < m; i++){
   variables[i] = revised[i];
  }
 }
 return;
}

int fxn::varHelp(int i, string *raw){
 node *current = function->pos();
 node *left = current->getLeft();
 node *right = current->getRight();
 string h;
 char c = current->gtype();
 int j = i;
 void *value = current->getValue();
 
 if(c == 'F'){
  function->goTo(left);
  j = varHelp(j,raw);
  
  function->goTo(right);
  j = varHelp(j,raw);
  
 } else if(c == 'V'){
  h = *((string *) value);
  raw[j] = h;
  j++;
 }
 
 return j;
}

// variable access
int fxn::numVar(){
 return num;
}

// evaluators
double fxn::evaluate(double *dd){
 int i;
 for(i = 0; i < num; i++){
  x[i] = dd[i];
 }
 return evaluate();
}

double fxn::evaluate(){
 function->gtop();
 double d = 0;
  
 d = evalHelp();
 
 return d;
}

double fxn::evalHelp(){
 node *current = function->pos();
 node *left = current->getLeft();
 node *right = current->getRight();
 char c = current->gtype();
 string h;
 int j = 0;
 void *value = current->getValue();
 runn funt = NULL;
 double a = 0;
 double b = 0;
 double d = 0;

 if(c == 'F'){
  funt = (runn) value;
  function->goTo(left);
  a = evalHelp();
  function->goTo(right);
  b = evalHelp(); 
  d = funt(a,b);

 } else if(c == 'V'){
  h = *((string *) value);
  
  for(j=0; h.compare(variables[j]) != 0; ++j){;}
  //cout << "Compare: " << variables[j] << endl;
  
  d = x[j];
 } else if(c == 'D'){
  d = ((double *) value)[0];
 }

 return d;
}

// Error Function
double error_init(double a, double b){
 exit(1);
}

// Operation Functions
double fxnCos(double a,double b){
 return cos(a*b);
}

double fxnSin(double a,double b){
 return sin(a*b);
}

double fxnTan(double a,double b){
 return tan(a*b);
}

double fxnExp(double a,double b){
 return exp(a*b);
}

double fxnPow(double a,double b){
 return pow(a,b);
}
double fxnAdd(double a,double b){
 return a+b;
}

double fxnSub(double a,double b){
 return a-b;
}

double fxnMult(double a,double b){
 return a*b;
}

double fxnDiv(double a,double b){
 if(b == 0){
  return error_init(1,1);
 } else{
  return a/b;
 }
}

double fxnAcos(double a,double b){
 return acos(a*b);
}

double fxnAsin(double a,double b){
 return asin(a*b);
}

double fxnAtan(double a,double b){
 return atan(a*b);
}

double fxnCosh(double a,double b){
 return cosh(a*b);
}

double fxnSinh(double a,double b){
 return sinh(a*b);
}

double fxnTanh(double a,double b){
 return tanh(a*b);
}

double fxnLn(double a,double b){
 return log(a*b);
}

double fxnPi(double a, double b){
 return 3.14159265;
}
