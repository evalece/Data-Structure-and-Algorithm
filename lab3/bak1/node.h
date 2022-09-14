/**
    ECE250
    node.h
    Purpose: save number input with two pointers connecting adjcent nodes
    Provides listList the right to modify function variables.

    Author Eva Liu
    Version 1.0  - 27/01/2020
*/

#include <iostream>

using namespace std; 

#ifndef NODE_H
#define NODE_H

class node {
public:

/*  
contain intrenal node info 
*/

node* parent;
node* ne;
node* nw;
node* sw;
node* se;

//name of the city
string name;
//logitude
float x;
// Latitude 
float y;
// Population 
int p;
// Cost of Living
float r;
// Average Net Salary
float s;


node();
node(string nn, float xx, float yy, int pp, float rr, float ss);
//copy constructor
node(node &p2);
~node(); 


};

#endif // LINKLIST_H