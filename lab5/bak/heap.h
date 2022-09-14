/**
    ECE250
    heap.h
    Purpose: storing city#, and the corresponding distance. This will be used in udgraph.cpp and h as a  array  of  type  heap.


    functionality: #3 is vector of type node. Use sort 

    Author Eva Liu ID:20724405 UWID:lj2liu
    Version 2.0  - 12/03/2020
*/


#include <iostream> 
#include <vector>       // std::vector
#include <algorithm>    // std::sort

using namespace std; 

//forward declaration 

//node contains edge weight and 2 vertices. 
//class node; 

#ifndef heap_H
#define heap_H

class heap{

public:
/** 
 constructors, destructors
 */

//in each node class, they will contain another node(called nod here) that makes up a distance called dis.
int nod;
//distance
double dis;

heap();
//copy constructor
heap(heap const &p2);

//a simple initialization  for drivers
heap(int node_in, double distance_in);

~heap(); 


};

#endif // heap_H



