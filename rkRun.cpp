/** 
 * rkRun.cpp
 * By: John Brock
 * Created: 14 Nov 2010
 * Modified: 14 Nov 2010
 * Purpose: This file takes a .rk file and outputs data for a solved graph
**/

#include "rk4.h"

int main(int argc, char **argv){
 FILE *in;
 
 if(argc != 2){
  cout << "Try ./rk4 in.rk" << endl;
  exit(1);
 }
 
 if((in = fopen(argv[1],"r")) == NULL){
  cout << "Is " << argv[1] << " even a real file?" << endl;
  exit(1);
 }

 rk4 *sol = new rk4(in);

 sol->solve();
 return 0;
}
