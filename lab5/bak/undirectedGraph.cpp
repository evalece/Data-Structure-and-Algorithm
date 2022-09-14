/**
    ECE250
    undirectedGraph.h
    Purpose: to store user input for edge weight and vertice (which two that made up the edge)info.


    Author Eva Liu ID:20724405 UWID:lj2liu
    Version 2.0  - 31/03/2020
*/

#include <iostream>
using namespace std; 

#include "undirectedGraph.h"
#include "heap.h"
/** 
 constructors and destructors
 */

undirectedGraph::undirectedGraph(){
    }


undirectedGraph::undirectedGraph(int previous_in, double current_cost_in){

previous=previous_in;
current_cost=current_cost_in;

}


//copy constructors
undirectedGraph::undirectedGraph(undirectedGraph const &p2) {
    previous= p2.previous;
    current_cost= p2.current_cost;
    connected= p2.connected;

    }

undirectedGraph::~undirectedGraph(){
    }


