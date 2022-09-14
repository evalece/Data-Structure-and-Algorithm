/**
    ECE250
    linkList.h
    Purpose: provide enque and deque and other linklist functions. 
    Provides services to call array of type node and perform dynamic allocations.

    Author Eva Liu
    Version 1.0  - 27/01/2020
*/


#include <iostream>

using namespace std; 

//forward declaration 

class node; 

#ifndef LINKLIST_H
#define LINKLIST_H

//linkList is the class that can gain access to node class and perform linklist functions
class linkList {

public:

int arraysize=0; 
node* current= nullptr; 
//left/front of the array a[0] a[1] ... a[n] right/back of the array
node* head= nullptr;  //head == the left most/ front of an array. 
node* tail= nullptr; // the right most (back) of an array

/** 
 constructors 
 */

linkList();
~linkList(); 

/**
prevent wild pointers when reassiging pointers
  Params: 
   target (in) - target pointer. 

 */
void cleanptr( node* target);
/**
 Add element at the front
   Params: 
   x (in) - number input (content).
 
*/
void enqueue_front (int x);


/**
 Add element at the end 
  Params: 
   x (in) - number input (content).
 */ 

void enqueue_back (int x);
//Remove element from the front
void dequeue_front();

/**
Remove element from the front
*/
void dequeue_back();
/**Clears the content of the deque if the queue is not already empty
 */
void clear();

/**
 Access the first element and compare to i, if equal, return success, else failure.
  Params: 
   iin (in) - number input (content).
 */
void front(int iin);
/**
 Access the last element and compare to i, if equal, return success, else failure
  Params: 
    iin (in) - number input (content).
 */
void back(int iin);

/**
 Test if deque is empty
 */
void empty();

/**
 Print all the values in the deque two times: • from front to back • from back to front
 */
void print();

/**
 delete element pointed by the pointer and free the space
  Params: 
   target (in) - target pointer. 

 */
void deleteEle (node* target);


/**
 counting the size of the array
 */
void size();


};

#endif // LINKLIST_H



