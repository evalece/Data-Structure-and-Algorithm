/**
    ECE250
    heap.h
    Purpose: save number input with directon pointers connecting adjcent nodes
    Provides tree and qrttest the right to modify function variables.

    Author Eva Liu ID:20724405 UWID:lj2liu
    Version 2.0  - 12/03/2020
*/


#include <iostream>

using namespace std; 

//forward declaration 

class node; 

#ifndef heap_H
#define heap_H

class heap{


public:

//the number of vertices in a mst. (This is defined as always being the first input.)
int m;

int insert_count;

//look up array helping #1 array
int lookup[];

//parent tracking array, aka #1 array. This array helps tracking parent. copy this array and recursively call parent will give an optimized parent. 
int pctrack[];

//a poiter to an array-- this will help tracking the edge weight inputs. A new intialization with new size may occur if the user uses too many 
//edge insertions. 
//functionality for this pointer:initailize a local array, use this array pointer to point at the array of node type. 
node* minheap;

/** 
 constructors 
 */

//initilize with tototal number of vertices that the user is going to insert.
heap(int m_in);
~heap(); 


//insertio of node
insert(node in);


};

#endif // heap_H



