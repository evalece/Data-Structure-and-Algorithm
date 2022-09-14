/**
    ECE250
    node.h
    Purpose: save number input with two pointers connecting adjcent nodes
    Provides listList the right to modify function variables.

    Author Eva Liu
    Version 1.0  - 27/01/2020
*/

#include <iostream>

using namespace std; 

#ifndef NODE_H
#define NODE_H

class node {
public:

/*  when append node afetr the current node, assign next node to the new node and ....
p_next_node_ = new Node{9.9, nullptr}; ece150 5.03 slide 
....change head (aka current node instance) to the next node
p_list_head=p_next_node_
*/

node* next;
node* prev; 
int number; 

node(int x);
~node(); 

};

#endif // LINKLIST_H