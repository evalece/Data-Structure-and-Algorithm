/**
    ECE250
    undirectedGraph.h
    Purpose: perform undirectedGraph calculation, record indertion info, check cycles and disconnection, check valid insertion, 
    initialize #1,#2,#3 array that are parent-child tracking (#1), degree tracking(#2) and sorted input (#3).

    functionality: #3 is vector of type node. Use sort 

    Author Eva Liu ID:20724405 UWID:lj2liu
    Version 2.0  - 12/03/2020
*/


#include <iostream> 
#include <vector>       // std::vector
#include <algorithm>    // std::sort
#include <math.h> 

using namespace std; 

//forward declaration 
class heap;

//node contains edge weight and 2 vertices. 
//class node; 

#ifndef undirectedGraph_H
#define undirectedGraph_H

class undirectedGraph{


public:

//degree of the current node

int degree;

//current city
int current;

//always store the pervious node/ city# that leads to a optimum traveling cost looking from the starting node/ city. 
// if the current node is a starting point, set this to a special number ... ie, 0. 
// a lookup table of O(n) is to help assigning city to numbers
int previous;

//current cost is defined by previous node + the edge weight to get to the current node/ city. 
//hence, current_cost is constantly checked and updated by the driver, along with the previous int. 
double current_cost;
/*

old notes:
an pointer to a vector array, initialized by driver to set the connected nodes (cities) with the correspodning cost. 
the array's index= city# , the content of the array is the distance looking from the current node (a local distance)
upon each insertion, two undirectedGraph are called and their edge cost is updated by driver.
*/

//an upate: create a type that uses index as city# to store city# (index) and corresponfing d, this will help 
//heapify process when we lost track on the array order. 
vector<heap> connected_h;

//the following is a copy of connected, used for heapify purposes.
vector<heap> connected_heapify;

//this array records the neighbouring nodes/cities of the current node.
//helps returning 
vector<int>neighbour;



/** 
 constructors, destructors
 */

undirectedGraph();
//copy constructor
undirectedGraph(undirectedGraph const &p2);

//a simple initialization  for drivers
undirectedGraph(int current_node,int previous_in, double current_cost_in);

void heapify(int asize1);

~undirectedGraph(); 


};

#endif // undirectedGraph_H



