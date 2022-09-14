/**
    ECE250
    node.cpp
    Purpose: save number input with two pointers connecting adjcent nodes
    Provides listList the right to modify function variables.

    Author Eva Liu
    Version 1.0  - 27/01/2020
*/

#include <iostream>
using namespace std; 

#include "node.h"

node::node(int x){

next= nullptr;
prev= nullptr; 
number= x; 

}

node::~node(){

next= nullptr;
prev= nullptr; 
delete next;
delete prev;

}
