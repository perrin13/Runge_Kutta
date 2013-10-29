/**
 * tree.cpp
 * John Brock
 * Date Created: 29 Oct 2010
 * Date Updated: 30 Oct 2010
 * Purpose: To implement the features of a tree class
**/

#include "tree.h"

//
// The following are the implementations of the node fxns
//
node::node(){
 left = NULL;
 right = NULL;
 value = NULL;
 type = 'N';
}

node::node(void *fun){
 left = NULL;
 right = NULL;
 value = fun;
 type = 'F';
}

node::node(double d){
 left = NULL;
 right = NULL;
 double *v = new double[1];
 v[0] = d;
 value = v;
 type = 'D';
}

node::node(const node &n){
 left = n.left;
 right = n.right;
 if(n.type == 'D'){
   double *v = new double[1];
   v[0] = ((double *)n.value)[0];
   value = (void *) v; 
 } else if (n.type == 'F'){
   value = n.value;
 }
 type = n.type;
}

node::~node(){
 left = NULL;
 right = NULL;
 if(type == 'D'){
  delete(((double *)(value)));
 } else if(type == 'F'){
  value = NULL;
 }

}

node *node::getLeft(){
 return left;
}

node *node::getRight(){
 return right;
}

void *node::getValue(){
 return value;
}

char node::gtype(){
 return type;
}

char node::gtype(char c){
  type = c;
  return type;
}

node *node::getLeft(node *n){
 left = new node(*n);

 return left;
}

node *node::getRight(node *n){
 right = new node(*n);
 
 return right;
}

void *node::getValue(void *fun){
 type = 'F';
 value = fun;
 
 return value;
}

void *node::getValue(double d){
 type = 'D';
 double *v = new double[1];
 v[0] = d;
 value = v;
 
 return value;
}


// implementations of tree fxns
tree::tree(){
 top = new node();
 position = top;
}

tree::tree(const tree &t){
 top = new node(*t.top);
 
 position = top;
 
 copyHelp(top);
 position = top;
 //FINISH
}

tree::tree(void *fun){
 top = new node(fun);
 position = top;
}

tree::tree(double d){
 top = new node(d);
 position = top;
}

tree::~tree(){
  deleteHelp(top);
}

void tree::gtop(){
 position = top;
}

void tree::goTo(node *n){
 position = n;
}

node *tree::pos(){
 return position;
}

void tree::addLeft(void *fun){
 node *nleft = new node(fun);
 position = position->getLeft(nleft);
}

void tree::addLeft(double d){
 node *nleft = new node(d);
 position = position->getLeft(nleft);
}

void tree::addLeft(node *n){
 position = position->getLeft(n);
}

void tree::addLeft(){
 node *nleft = new node();
 position = position->getLeft(nleft);
}

void tree::addRight(void *fun){
 node *nright = new node(fun);
 position = position->getRight(nright);
}

void tree::addRight(double d){
 node *nright = new node(d);
 position = position->getRight(nright);
}

void tree::addRight(node *n){
 position = position->getRight(n);
}

void tree::addRight(){
 node *nright = new node();
 position = position->getRight(nright);
}

void tree::copyHelp(node *n){
 if(n->getLeft() == NULL)
   return;

 addLeft(n->getLeft());
 copyHelp(position);
 addRight(n->getRight());
 copyHelp(position);

 return;
}

void tree::deleteHelp(node *n){
 if(n->getLeft() == NULL){
  delete(n); 
  return;
 }

 position = n->getLeft();
 deleteHelp(position);
 position = n->getRight();
 deleteHelp(position);
 
 delete(n);
 return;
}
