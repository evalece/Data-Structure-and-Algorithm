/**
    ECE250
    heap.h
    Purpose: to store user input for edge weight and vertice (which two that made up the edge)info.


    Author Eva Liu ID:20724405 UWID:lj2liu
    Version 2.0  - 31/03/2020
*/

#include <iostream>
using namespace std; 


#include "heap.h"
/** 
 constructors and destructors
 */

heap::heap(){
    nod1=0;
    nod2=0;
    dis=0;
}

heap::heap(int node_in, double distance_in){
    //nod2 is the connected index 
    nod1=node_in;
    dis=distance_in;
}


//copy constructors
heap::heap(heap const &p2) {

    nod1=p2.nod1;
    nod2=p2.nod2;
    dis=p2.dis;

    }

heap::~heap(){
    }

