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

node::node(){

    parent= nullptr;

    ne= nullptr;
    nw= nullptr;
    sw= nullptr;
    se= nullptr;

}

//copy constructor

node::node(node &p2) {


    parent= p2.parent;
    ne = p2.ne; 
    nw = p2.nw; 
    sw = p2.sw; 
    sw = p2.se; 

    name = p2.name;
    x = p2.x;
    y = p2.y;
    p = p2.p;
    r = p2.r;
    s = p2.s;



    }

node::node(string nn, float xx, float yy, int pp, float rr, float ss){

    parent= nullptr;

    ne= nullptr;
    nw= nullptr;
    sw= nullptr;
    se= nullptr;

    name= nn;
    x=xx;
    y=yy;
    p=pp;
    r=rr;
    s=ss;

}

node::~node(){

parent= nullptr;

ne= nullptr;
nw= nullptr;
sw= nullptr;
se= nullptr;
delete parent;
delete ne;
delete nw;
delete sw;
delete se;
}
