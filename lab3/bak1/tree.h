/**
    ECE250
    tree.h
    Purpose: provide enque and deque and other tree functions. 
    Provides services to call array of type node and perform dynamic allocations.

    Author Eva Liu
    Version 1.0  - 27/01/2020
*/


#include <iostream>

using namespace std; 

//forward declaration 

class node; 

#ifndef tree_H
#define tree_H

//tree is the class that can gain access to node class and perform tree functions
class tree {


public:


//counting tree size 

int size=0; 
node* root;
node* toInsert; 

/** 
 constructors 
 */
tree();
~tree(); 

//inserting tree new leaves or starting a new root with dynamic allocations. 
void insert(node *& p, node *& i);

//pre entire tree using inoder traveral
void print(node* rootp);

void cleanptr(node* c);

//create the target new node for calling recursive call on insertion.
void forinsert(string nn, float xx, float yy, int pp, float rr, float ss); 


};

#endif // tree_H



