/**
    ECE250
    node.h
    Purpose: to store user input for edge weight and vertice (which two that made up the edge)info for heap tree and cycle/ disconnect (#1) array.
    Initialization of parent, child and weight must be given and they should follow assign rules in the .h file.


    Author Eva Liu ID:20724405 UWID:lj2liu
    Version 2.0  - 31/03/2020
*/

#include <iostream>
using namespace std; 


#include "node.h"
/** 
 constructors and destructors
 */

node::node( int parent_in, int child_in, double weight_in){

    weight=weight_in;
    parent=parent_in;
    child=child_in;
    }


node::node(){

    //zero means no proper initialization occurs. 

    weight= 0;
    parent= 0;
    child= 0;

    }


//copy constructors
node::node(node const &p2) {
    weight= p2.weight;
    parent= p2.parent;
    child= p2.child;

    }

node::~node(){
    }


