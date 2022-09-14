/**
    ECE250
    mst.h
    Purpose: perform mst calculation, record indertion info, check cycles and disconnection, check valid insertion, 
    initialize #1,#2,#3 array that are parent-child tracking (#1), degree tracking(#2) and sorted input (#3).

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
class node; 

#ifndef mst_H
#define mst_H

class mst{


public:

//minimum spanning tree weight count
double mst_weight;

//the number of vertices in a mst (defined as always being the first input of msttest).
int m;

bool not_con;

//#1 array tracks parent with recursion O(m).
vector<int> check; 

//#2 array tracks degree of each vertex O(1).
vector<int> degree; 

//#3 dynamically growing size upon user insertions. Use sort to find the minimum sort. O(m*log (m)). Push-back O(m)
vector<node> net; 

//helping allocating user input and pass it to vector.
node* in; 

//keep tracking initiated vertex
int* vertex_count;


/** 
 constructors, destructors
 */

mst();
mst(int m_in);
~mst(); 


//copy constructors
mst(mst const &cp);


/////////first part of functionality: insertion of nodes, delete and sort them when needed. 

//insertion of node by push_back() vector #3.
void insert(int parent_in, int child_in, double weight_in);

void cleanptr(node* target);

//deletion on edges; if deleted or found, then true. otherwise, false.
bool del(int parent_in, int child_in);

//checking the degree of the node v by looping through the net work, the output is the original network vertex degree
int degreev(int v);


////////second part of the functionality: sort and find mst


// for vector net.
void sortnet();

//for vector check, recursively call parent. Used in disjoint set.
int findparent( int a);

void mintree();

};

#endif // mst_H



