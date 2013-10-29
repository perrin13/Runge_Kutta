/**
 * tree.h
 * John Brock
 * Date Created: 28 Aug 2010
 * Date Updated: 30 Oct 2010
 * Purpose: This file holds the specifications for the tree class
**/

#include <stdio.h>
#include <stdlib.h>

#ifndef TREEE_H
#define TREEE_H



// node class for tree
class node{
 public:
 //Constructors
 node();
 node(void *fun);
 node(double);
 node(const node &n);

 // Destructors
 ~node();

 // Methods
 node *getLeft();	    // Returns a pointer to the left node
 node *getRight();	    // Returns a pointer to the right node
 void *getValue();	    // Returns the nodes contents
 char gtype();		    // Returns character representing nodes data type

 node *getLeft(node *n);    // Sets the left node pointer
 node *getRight(node *n);   // Sets the right node pointer
 void *getValue(void *fun); // Puts a double function pointer in the node
 void *getValue(double);    // Puts a double in the node
 char gtype(char);	    // Changes the type

 private:
 node *left;		    // Pointer to the left node
 node *right;		    // Pointer to the right node
 void *value;		    // Pointer to the node's value
 char type;		    // Character representing value's type
};

// tree class
class tree{
 public:
 // Constructors
 tree();		    // Default constructor
 tree(const tree &t);	    // Copy constructor
 tree(void *fun);
 tree(double);
 ~tree();		    // Default destructor

 // Methods
 void gtop();
 void goTo(node *);
 node *pos();
 void addLeft(void *fun);// Adds a node to the left w/ double fxn pointer
 void addLeft(double);      // Adds a node to the left w/ a double
 void addLeft(node *);      // Adds the given node to the left
 void addLeft();
 void addRight(void *fun);// Adds a node to the right w/ double fxn pointer
 void addRight(double);	    // Adds a node to the right w/ a double
 void addRight(node *);	    // Adds the given node to the right
 void addRight();
 
 node *position;
 private:
 node *top;
 void copyHelp(node *);
 void deleteHelp(node *);
};


#endif
