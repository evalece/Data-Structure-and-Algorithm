/**
    ECE250
    ugDriver.h
    Purpose: ugDriver collects information from each inserted nodes/cities and record the minimum traveling path to the destination through 
    array approach. This array** uses its index to represent each node/ city inserted. (Since the cities are string, a look-up table 
    is applied to help converting their names; O(n) at worst operation complexity). A recursion of finding parent starts from the 
    end node to the starting node. This arry** of vector and ugDriver type contains the city's current minimum cost and its previous node/ city.

    ** the complexity of the array** is O(n) for worst opertation time complexity. 

    Insertion: the driver will modify each node/city object upon insertion. It takes care the "local view point" of the distances among nodes/
    cities and the "global view point" of distance as the test.cpp describes.
 
    Author Eva Liu ID:20724405 UWID:lj2liu
    Version 2.0  - 12/03/2020
*/




//forward declaration 


#ifndef ugDriver_H
#define ugDriver_H

#include <iostream> 
#include <vector>       // std::vector
//#include <algorithm>    // std::sort


class undirectedGraph;
class  heap; 

using namespace std; 

class ugDriver{


public:

//the number of total valid node inserted.
int nodes;

//the number of total valid edge inserted.
int global_edge_count;

//array** as described above, index = node/city#, the content that this array is using is the current minimum cost and the previous node/city
//information. 

//an  additional reset to make all ndes with infinite distance is required upon each function call to .... ie, find path and find cost.
//the idea is.... all nodes, if connected, will be visited. 
vector<undirectedGraph> path;

//a pointer to access individual node/ city for local view point;
vector<undirectedGraph> modi;

//this array keeps track of visited nodes, index number== node/ city#. The content indicates if the node has been visited. O(1).
int* visited;

//a look-up table to convert city to numbers
vector<string> lookup;

//a pointer for allocating new node space for array. 
//side note: need a clean ptr at this scope later for clear or exist function.
//to clean, need looping through the modi array.
//this is optional
undirectedGraph* nodeptr;




/** 
 constructors, destructors
 */
ugDriver();

ugDriver(int nodes_in,int edge_in);
//copy constructor
ugDriver(ugDriver const &p2);

~ugDriver(); 



bool insert(string city_in);

//retun assign lookup values to cities.
int look_up(string city_in);

//Assigns a distance (d) to the edge (road) connecting two cities (name1 and name2). 
bool setd(string name1, string name2, double d);

//checking if the city exist
bool look_up_check(string city_in);

//Prints the degree of the city(name).
int degree(string name);

/*
//Returns the number of nodes (cities) in the graph.
int graph_nodes();

//Returns the number of edges (roads) in the graph.
int graph_edges();
*/

//Prints the distance between two cities (name1 and name2) along the edge directly connecting them.
// Note: Two cities (name1 and name2) must be adjacent to have a valid direct distance.
double d(string name1, string name2);

double shortest_d(int index1, int index2);

void relex(int in);

void heap_path(int sizein);

void ini_visit();

void getmin();

void print_path(int index1, int index2);



};

#endif // ugDriver_H



