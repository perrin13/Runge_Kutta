/**
* getnum.c
* By: John Brock
* CPSC210
* Date: 27 Jan 2008
* Purpose: To get numbers for other programs
**/
#include<stdio.h>
#include<stdlib.h>
#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <locale>
#include <sstream>
using namespace std;
#include "getnum.h"

// 
// getint(FILE *fp) 
// Parameters:
// FILE *fp - a pointer to an fopened file
// Output:
// int - returns the next integer in *fp ignoring comments preceeded
//   by a #, and returning an error otherwise
//
int getint(FILE *fp);

int getint(FILE *fp){
    char str[130];
    int g, h = -1;

    while(h < 0){
      g = fscanf(fp, " %i", &h);
      if(g < 0){
	fprintf(stderr, "Premature end-of-file\n");
	exit(1);
      }
      if(g == 0){
	fgets(str, sizeof(str), fp);
	if(str[0] != '#'){
	   fprintf(stderr, "Garbage in PPM header\n");
	   exit(1);
	}
        h = -1;
      }
    }
     // cout << h << endl;
     return h;
}

//  
//  double getdouble(FILE *fp)
// FILE *fp - a pointer to an fopened file
// Output:
// double - returns the next double in *fp ignoring comments preceeded
//   by a #, and returning an error otherwise
//
double getdouble(FILE *fp){
    char str[130];
    int g, k= -1; 
    double h;

    while(k < 0){
      g = fscanf(fp, " %lf", &h);
      if(g < 0){
        fprintf(stderr, "Premature end-of-file\n");
        exit(1);
      }
      if(g == 0){
        fgets(str, sizeof(str), fp);
        if(str[0] != '#'){
           fprintf(stderr, "Garbage in header\n");
           exit(1);
        }
        k = -1;
      } else{
        k = 1;
      }
    }
    // cout << h << endl;
     return h;
}

string getstring(FILE *fp){
    char str[130];
    int g, k= -1; 
    string h = "";

    while(k < 0){
      g = fscanf(fp, " %s", str);
      if(g < 0){
        fprintf(stderr, "Premature end-of-file\n");
        exit(1);
      }
      if(g == 0){
        fgets(str, sizeof(str), fp);
        if(str[0] != '#'){
           fprintf(stderr, "Garbage in header\n");
           exit(1);
        }
        k = -1;
      } else{
        if(str[0] == '#'){
         fgets(str, sizeof(str), fp);
         k = -1;
        } else{
         k = 1;
        }
      }
    }
    
    h += str; 
    // cout << h << endl;
    return h;
}

