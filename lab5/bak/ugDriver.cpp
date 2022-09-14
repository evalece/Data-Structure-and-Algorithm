/**
    ECE250
    ugDriver.cpp
    Purpose: to store user input for edge weight and vertice (which two that made up the edge)info.


    Author Eva Liu ID:20724405 UWID:lj2liu
    Version 2.0  - 31/03/2020
*/

#include <iostream>
using namespace std; 


#include "ugDriver.h"
#include "undirectedGraph.h"
#include "heap.h"
#include <math.h>
/** 
 constructors and destructors
 */
ugDriver::ugDriver(){
    //start counting nodes from 0. 
    nodes=0;
}

//insert looks-up the city in converstion table
 bool ugDriver::insert(string city_in){

     int index= look_up(city_in);

     //if the index number is less than modi.size()-1, then no new city is created, so we update the exisiting city.
     //However, this is a insert function, we don't update anything unless a new node is detected

     if(index> modi.size()-1){
         //new node is detected, we push back on modi;    
         modi.push_back(undirectedGraph()); 
         return  true;     
     }

    //this says the node is already inserted so it didn't return true in the previous if statement.
     return false;

}

//looking up or create for city index
int ugDriver::look_up(string city_in){
    bool found= false;
    //go through a look up table process
    for(int i=0; i< lookup.size(); i++){
        if(lookup[i]==city_in){
        found =true;
        ////////
        cout<< "i="<< i <<endl;
        return i;
        }
    }
    if(found ==false){
        lookup.push_back(city_in);
        
        /////
        cout<<"lookup.size()-1=" <<lookup.size()-1 <<endl;
        return lookup.size()-1;

    }

}

//checking if the city exist, aka the "s" command
bool ugDriver::look_up_check(string city_in){
    bool found= false;
    //go through a look up table process
    for(int i=0; i< lookup.size(); i++){
        if(lookup[i]==city_in){
        found =true;     
        }
    }

     return found;

}

//Assigns a distance (d) to the edge (road) connecting two cities (name1 and name2). 
bool ugDriver::setd(string name1, string name2, double d){

    //run look up check first, make sure that cities are there
    if(look_up_check(name1) && look_up_check(name2)) {
        undirectedGraph* editptr;
        
        int index1=look_up(name1);
        int index2=look_up(name2);

        //a local point view from index1 city
        editptr=&modi[index1];
        
        //expand vector size based on index2 
        if(editptr->connected.size()-1<index2){
            for(int i= index2-editptr->connected.size()-1; i<index2-1;i++){
                //assume  these nodes are not visited yet because we are just opening spaces for them in vector array.
                //we assign connected node= -1, which means none, and infinity for invalid input. 
                //new idea: or, simply don't initialize a:
                heap a= heap(-1,INFINITY);
                editptr->connected.push_back(a);
            }    
        }

        heap b= heap(index2,d);
        editptr->connected[index2]=b;

        //clean editptr
        editptr=nullptr;

        ////////a local point view from index2 city   
        editptr=&modi[index2];
        
        //expand vector size based on index2 
        if(editptr->connected.size()-1<index1){
            for(int i= index1-editptr->connected.size()-1; i<index1-1;i++){
                //assume  these nodes are not visited yet because we are just opening spaces for them in vector array.
                   heap a= heap(-1,INFINITY);
                  editptr->connected.push_back(a);
            }    
        }
        heap b= heap(index1,d);
        editptr->connected[index1]=b;

        //clean editptr
        ////////note sure if this assigns connecred[index1]=nullptr, it shouldn't..
        editptr=nullptr;

        //since we are doing bool
        return true;
    }//end of run look up check first is true
    return false;
}

int ugDriver::degree(string name){
    
    if(look_up_check(name)==1){
        // the node exists
        
        //check index number
        int index=look_up(name);

        undirectedGraph* editptr;
        editptr= &modi[index];

        int degree= 0;
        for(int i=0;i< editptr->connected.size();i++){
            if(editptr->connected[i].dis!=INFINITY){
                degree++;
            }

        }//end of for loop
        return degree;
    }//end of if node exist

    //meaning that the degree function fails, either node doesn't exist or other reasons
    return -1;
}


//Returns the number of nodes (cities) in the graph.
int ugDriver::graph_nodes(){  
}

//Returns the number of edges (roads) in the graph.
int ugDriver::graph_edges(){
}


//Prints the distance between two cities (name1 and name2) along the edge directly connecting them.
// Note: Two cities (name1 and name2) must be adjacent to have a valid direct distance.
double ugDriver::d(string name1, string name2){
    if(!look_up_check(name1)||!look_up_check(name1)){
        //checking if if these two cities exists
        //this will be consider funtion d has failed with the input given.
        return INFINITY;
    }
    
    //starting from here is the execution of two nodes actually exist in our system.
    int index1= look_up(name1);
    int index2= look_up(name2);
    //pointer to access data
    undirectedGraph* editptr;
    editptr=&modi[index1];
    double d1= editptr->connected[index2].dis;
    editptr= nullptr;

    //double check index 2 distance with index 1:
    editptr=&modi[index2];
    double d2= editptr->connected[index1].dis;
    editptr= nullptr;

    if(d1==d2){
        return d1;
    }

    //////for degug:
    else{
        cout<<"d1="<< d1<<endl;
        cout<<"d2="<< d2<<endl;
    }  

}



ugDriver::~ugDriver(){
    }


