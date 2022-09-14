/**
    ECE250
    tree.h
    Purpose: provide enque and deque and other tree functions. 
    Provides services to call array of type node and perform dynamic allocations.

    Author Eva Liu ID:20724405 UWID:lj2liu
    Version 1.0  - 12/03/2020
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
//a pointer responsible for deleting dynamic allocated spaces.
node* todel;

node* target;
//pointing at the maximum solution for q_max


int max;
int total;
int min;

/** 
 constructors 
 */
tree();
~tree(); 

//inserting tree new leaves or starting a new root with dynamic allocations. 
bool insert(node* p, node* i);

//pre entire tree using inoder traveral
void print(node* rootp);

void cleanptr(node* c);

//create the target new node for calling recursive call on insertion.
void forinsert(string nn, double xx, double yy, int pp, int rr, int ss); 

//search uses root and dummy and recusrively call itseld with corresponding direction node + dummy node. p=recursived parent, i= dummy node.
void search(node* p, node* i);

//this search returns the target node in  node* target, it may return nullptr if no answer is found.
node* searchnode(node* p, node* i);

//resursive comparsion (maximum) of criteria attr with desigated root rootp.
void q_max(node* rootp, string attr);

//resursive summation of criteria attr with desigated root rootp.
void q_total(node* rootp, string attr);

//resursive comparsion (minimum) of criteria attr with desigated root rootp.
void q_min(node* rootp, string attr);

//like print, delete visits every node and delete (aka clean pointer) for each of them
void clear( node* a);

};

#endif // tree_H



