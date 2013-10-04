/** 
 * Runge Kutta 4th Order Method
 * By: John Brock
 * Created: 08/25/2010
 * Modified:08/25/2010
 * Supported Function Types: 
**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv){
 FILE *fxn;
 
 if(argc != 2){
    fprintf(stderr, "Please run this program as ./rk4 FILENAME\n");
    exit(1);
 }
 fprintf(stdout, "File: %s\n", argv[1]);
 
 fxn = fopen(argv[1], r);
 
 fclose(fxn);
 return 0;
}
