/**
    ECE250
    node.h
    Purpose: to store user input for edge weight and vertice (which two that made up the edge)info for heap tree and cycle/ disconnect (#1) array.


    Author Eva Liu ID:20724405 UWID:lj2liu
    Version 2.0  - 31/03/2020
*/

#include <iostream>

using namespace std; 

#ifndef NODE_H
#define NODE_H

class node {
public:

/*  
rules for assigning: parent is always the smaller number. 
weight: always a positive number. 
*/

double weight;
int child;
int parent; 



node();
node(double weight_in, int parent_in, int child_in);
//copy constructor
node(node const &p2);
~node(); 


};

#endif // NODE_H