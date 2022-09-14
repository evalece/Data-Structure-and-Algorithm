/**
    ECE250
    node.h
    Purpose: save number input with directon pointers connecting adjcent nodes
    Provides tree and qrttest the right to modify function variables.

    Author Eva Liu ID:20724405 UWID:lj2liu
    Version 2.0  - 12/03/2020
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

node* ne;
node* nw;
node* sw;
node* se;

//name of the city
string name;
//logitude
double x;
// Latitude 
double y;
// Population 
int p;
// Cost of Living
int r;
// Average Net Salary
int s;


node();
node(string nn, double xx, double yy, int pp, int rr, int ss);
//copy constructor
node(node const &p2);
~node(); 


};

#endif // LINKLIST_H