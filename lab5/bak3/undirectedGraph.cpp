/**
    ECE250
    undirectedGraph.h
    Purpose: to store user input for edge weight and vertice (which two that made up the edge)info.


    Author Eva Liu ID:20724405 UWID:lj2liu
    Version 2.0  - 31/03/2020
*/

#include <iostream>
#include <math.h>
using namespace std; 

#include "undirectedGraph.h"
#include "heap.h"
/** 
 constructors and destructors
 */

undirectedGraph::undirectedGraph(){
    heap a(0,INFINITY);
    connected_h.push_back(a);
    degree=0;
    }


undirectedGraph::undirectedGraph(int current_node,int previous_in, double current_cost_in){

current=current_node;
previous=previous_in;
current_cost=current_cost_in;
degree=0;

}


//copy constructors
undirectedGraph::undirectedGraph(undirectedGraph const &p2) {
    previous= p2.previous;
    current_cost= p2.current_cost;
    connected_h= p2.connected_h;
    degree=p2.degree;
     current=p2.current;

    }

undirectedGraph::~undirectedGraph(){
    }

//input the size of the array, for heapify an existing array, we increase the array size one by one, this is Min heap
 void undirectedGraph::heapify(int asize1){
     int asize=asize1-1; //minus 1 for index

     //heapify an array that is not binary heap yet
     //so call heapify on the array, starting with the first element and eventually cover all elements in the array
       // cout<< "in heapify"<<endl;

        //cout<<"connected_heapify.size()="<< connected_heapify.size()<<endl;

        /*

        for(int i=0; i< connected_heapify.size(); i++){
            cout<< "connected_heapify["<<i <<"]="<<connected_heapify[i].dis<<endl;
        }
        */

        ///////
    // cout<< "asize="<<asize<<endl;

    //we do not heapify array with just one element
    if((asize)/2>=0){   
       //  cout<< "in heapify 1"<<endl;

    //this is the index of parent we want to compare with
    int asize_mod2= floor((asize)/2);  //mius 1 because we are doing index. index = array size-1 

  //cout<< "in heapify 1.1"<<endl;
    /////debug 

    /*
    cout<<"asize_mod2="<<asize_mod2<<endl;

    cout<<"connected_heapify[asize_mod2].dis="<<connected_heapify[asize_mod2].dis<<endl;
    cout<<"connected_heapify[asize-1].dis="<<connected_heapify[asize-1].dis<<endl;
    */

    //case where we need to move things up:

    if(asize!=asize_mod2){

        /*

        cout<<  "in heapify 1.2"<<endl;

        cout<< "asize_mod2="<< asize_mod2<<endl;
    
        cout<< "connected_heapify[asize_mod2].dis="<<connected_heapify[asize_mod2].dis<<endl;
        cout<< "connected_heapify[asize-1].dis="<<connected_heapify[asize].dis <<endl;
        cout<<"asize_mod2=" <<asize_mod2<<endl;
        cout<<"asize=" <<asize<<endl;

         cout<<"asize-1=" <<asize-1<<endl;
         */

        if(connected_heapify[asize].dis < connected_heapify[asize_mod2].dis){
        /////cout<< "in heapify 2"<<endl;
            /////
              //  cout<< "swap "<< connected_heapify[asize-1].dis<<" and "<< connected_heapify[asize_mod2].dis<<endl;
            swap(connected_heapify[asize],connected_heapify[asize_mod2]);

            //recursion of heapify, keep compare with the upper parent 
         ////   cout<< "in heapify 3"<<endl;

            heapify(asize_mod2+1);
        }

    }//end of if(asize-1>=0)


    }//end if((asize-1)/2>=0)

    return;


 }


 /*

     for(int i=0; i< connected_heapify.size(); i++){


        
    }


 */


