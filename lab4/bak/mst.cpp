/**
    ECE250
    heap.cpp
    Purpose: stores edge weight and thier vertic, each heap element is made of class node instance. A class node instance contains the edge 
    weight (of dounle value) and two vertices (the vertices that made up the edge). 
    
    Since the Greedy Method selects the minimum edge, we use minimum heap tree to pop out the minimum node each time. During each pop out, 
    another array will check to see if there is a cycle (using disjoint set). If a cycle is detected, the totoal weight count
    will jump to the next pop-out.3

    
    Operating flow: In Greedy Method, we want to count the minimum edge cost by counting n-1 edge weights. Hence, we pop the heap.
    *(n equal to the current total number of vertices, the vertices that the user has inserted).

    Another array will constantly checeking the existance of a cycle (see detail in #1). If a cycle exists, the current edge weight will not
    be taken into account. The array (#1) will also check disconnected nodes at the end of n-1 pops.

    A minimum heap tree is created as mttest called the class with argument int m.Hence, upon initializing, the vertice totoal (int m) will be passed to create an array of the heap tree to create
    an array of size m. 

    This heap tree will take inserted nodes (edge weight and the two vertices) and edge weight and put all of them into a minimum tree. 


    #1 array is an important member function: 
    purpose: check cycles and disconnections.
    
    Two arrays: one for parent tracking, one for index look up. Index look up assigns 1,2,3...m to the chind nodes (child defined as the greater vertex
    # in the node)
    Tracking array uses array index = child node in node, and parent node as stored value. The array[parent]= -k, k= number of child. The array initialize the 
    first inserted node's parent as "-1" and others as 0; only non-zero value counts. 

    index array will only be ran when the input child exceeds m, ie, m=3 we should have vertices 1, 2, 3. However, if we have 1, 2, 100: then 100 will be mapped to 3. And any future insertion with 
    parent/ child = 100 will be automatically converted to the mapped value.  ----performance is O(m), but this will only happend in cases where the input value is 
    not reasonable. If assuming input value are reasonable, this is O(1) (As we only need to check if input node# are greater than m).

    additional note: we can have infinite number of edges so user can insert infinite nodes. The min heap tree can grow infinitely.
    However, when calling minimum spanning tree, we will start poping the minimum edge weight and checking for cycles. 

    Author Eva Liu ID:20724405 UWID:lj2liu
    Version 2.0  - 31/03/2020
*/

#include <iostream>
using namespace std; 

#include "node.h"


#include <iostream>
#include "node.h"
#include "heap.h"


using namespace std; 

/** 
 constructors and destructors
 */
heap::heap(int m_in){

    m=m_in;

    //tracking the array index increament(used by lookup).
    insert_count=0;

    //initialization on #1 array, m+1 size because the array index needs to match the vertice number, which doesn't contain 0. 
    lookup[m+1]=0;
    
}


heap::insert(node in){

    //first node insertion 
    if(insert_count==0){
        lookup[in.parent]=-1; //negative -k means this node is a parent with k child/children. 
        lookup[in.child]= in.parent;
        minheap[1]=in;
        insert_count++;
    }
    //otherwise, this insertion is not the first node, several function needs to be called.
    /*functions to be called:
    1. heapify (parents should always be less than child).
    2. array index check: if lookup is needed, if parent and child be greater than m, if so, assign a new value to them.
    */

    else{

    }

}


//lookup is called when node parent or child be greater than m.
//can be called by insert, input is the value of parent or child or both if they exceed m.
//return the new index.
int heap::lookup(int num){
bool mapped=false;
int i;
//checkiing if the number is already mapped to a number.
while (i< m+1 && mapped== false){
    if(lookup[i]==num){
        mapped=true;
        //i is the assigned mapping. use this instead of num
        return i;
        }

    //otherwise keep search for mapped value.
    i++
    }

    if(mapped==false){

    
    }

}



heap::~heap() {}





    


