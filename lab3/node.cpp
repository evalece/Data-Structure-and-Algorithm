/**
    ECE250
    node.cpp
    Purpose: save number input with directon pointers connecting adjcent nodes
    Provides tree and qrttest the right to modify function variables.

    Author Eva Liu ID:20724405 UWID:lj2liu
    Version 2.0  - 12/03/2020
*/

#include <iostream>
using namespace std; 

#include "node.h"
/** 
 constructors and destructors
 */
node::node(){

    ne= nullptr;
    nw= nullptr;
    sw= nullptr;
    se= nullptr;

}

node::node(node const &p2) {



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


//copy constructors
node::node(string nn, double xx, double yy, int pp, int rr, int ss){

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

ne= nullptr;
nw= nullptr;
sw= nullptr;
se= nullptr;
delete ne;
delete nw;
delete sw;
delete se;
}
