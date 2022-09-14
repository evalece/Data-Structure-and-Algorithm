/**
    ECE250
    ugDriver.cpp
    Purpose: to store user input for edge weight and vertice (which two that made up the edge)info.


    Author Eva Liu ID:20724405 UWID:lj2liu
    Version 2.0  - 31/03/2020
*/

#include <iostream>
#include <math.h>


#include "undirectedGraph.h"
#include "heap.h"
#include "ugDriver.h"

using namespace std; 

/** 
 constructors and destructors
 */
ugDriver::ugDriver(int nodes_in, int edge_in){
    //start counting nodes from 0. 
    nodes=nodes_in;
    global_edge_count=edge_in;
     //initialize modi, an array storing node info with their info(i.e. previous node, current cost and heap structure on neighbour nodes)
    //initialize with node=0, previous node=-1, and distance from -1 to 0 is infinity.
    undirectedGraph a(0,-1,INFINITY);
    modi.push_back(a);
}


ugDriver::ugDriver(){
    //start counting nodes from 0. 
    nodes=0;
    global_edge_count=0;
    //initialize modi, an array storing node info with their info(i.e. previous node, current cost and heap structure on neighbour nodes)
    //initialize with node=0, previous node=-1, and distance from -1 to 0 is infinity.
    undirectedGraph a(0,-1,INFINITY);
    modi.push_back(a);

}

//copy constructor
ugDriver::ugDriver(ugDriver const &p2){

    nodes=p2.nodes;
    global_edge_count=p2.global_edge_count;
    path=p2.path;
    modi=p2.modi;
    visited=p2.visited;
    lookup=p2.lookup;
    nodeptr=p2.nodeptr;

}


//insert looks-up the city in converstion table
bool ugDriver::insert(string city_in){

    //first checking if the  city already exist 

     int index= look_up(city_in);

     //if the index number is less than modi.size()-1, then no new city is created, so we update the exisiting city.
     //However, this is a insert function, we don't update anything unless a new node is detected
    //-2 because index start from 0

        int modi_size= modi.size()-2;
        if(index> modi_size){
         //new node is detected, we push back on modi;  
         undirectedGraph b(index,-1,INFINITY);
         modi.push_back(undirectedGraph(b)); 

         //increase nodes count
         nodes++;
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
        ///////cout<< "i="<< i <<endl;
        return i;
        }
    }
    if(found ==false){
        lookup.push_back(city_in);
        
        /////
        //////cout<<"lookup.size()-1=" <<lookup.size()-1 <<endl;
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

        ///////cout<< "&modi[index1]=" <<&modi[index1]<<endl;
        ///////cout<<"editptr->current_cos"<<editptr->current_cost<<endl;

        ////////cout<<"editptr->connected.size()="<<editptr->connected_h.size() <<endl;
        /////////cout<<"index2="<<index2<<endl;

        int aa= editptr->connected_h.size();


        //expand vector size based on index2 
        if(aa-2<index2){
            for(int i= aa-2; i<index2-1;i++){
                //assume  these nodes are not visited yet because we are just opening spaces for them in vector array.
                //we assign connected node= -1, which means none, and infinity for invalid input. 
                //new idea: or, simply don't initialize a:
                heap a= heap(-1,INFINITY);
                editptr->connected_h.push_back(a);

            }    
        }


        ///////cout<<"editptr->connected.size()="<<editptr->connected_h.size() <<endl;

        heap b1= heap(index2,d);
        //a check ptr for checking distance
         
        heap* checkptr= &editptr->connected_h[index2];
        
        if(checkptr->dis==INFINITY) {
           ////// cout<<"checkptr->dis==INFINITY" <<endl;
            global_edge_count++;
             editptr->degree++;
            ////// cout<<" editptr->degree=" << editptr->degree<<endl;
        }
     
        editptr->connected_h[index2]=b1;

     
        //clean editptr
        editptr=nullptr;
        checkptr=nullptr;
        delete checkptr;

        ////////a local point view from index2 city   
        editptr=&modi[index2];

        int bb= editptr->connected_h.size();
         editptr->degree++;
        //expand vector size based on index2 
        if(bb-2<index1){
            for(int i= bb-2; i<index1-1;i++){
                //assume  these nodes are not visited yet because we are just opening spaces for them in vector array.
                //we assign connected node= -1, which means none, and infinity for invalid input. 
                //new idea: or, simply don't initialize a:
                heap a= heap(-1,INFINITY);
                editptr->connected_h.push_back(a);
    
            }    
        }

        heap b2= heap(index1,d);
        editptr->connected_h[index1]=b2;

        //clean editptr
        ////////note sure if this assigns connecred[index1]=nullptr, it shouldn't..
        editptr=nullptr;
        delete editptr;

        //since we are doing bool
        return true;
        
    }//end of run look up check first is true
    return false;
}


//return the degree of a city  O(n)
int ugDriver::degree(string name){
    
    if(look_up_check(name)==1){
        // the node exists
        
        //check index number
        int index=look_up(name);

        undirectedGraph* editptr;
        editptr= &modi[index];
        int aa= editptr->degree;
        //increase degree by one
        return aa;
    }//end of if node exist

    //meaning that the degree function fails, either node doesn't exist or other reasons
    return -1;
}

/*
//Returns the number of nodes (cities) in the graph.
int ugDriver::graph_nodes(){  

    return nodes;
}

//Returns the number of edges (roads) in the graph.
int ugDriver::graph_edges(){

    return global_edge_count;
}
*/

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
    //index is checkable:
    double d1=0;
    if(editptr->connected_h.size()>index2) {
    d1= editptr->connected_h[index2].dis;
    }
    editptr= nullptr;

    //double check index 2 distance with index 1:
    editptr=&modi[index2];
    double d2=0;
    if(editptr->connected_h.size()>index1){
     d2= editptr->connected_h[index1].dis;
    }
    editptr= nullptr;

    if(d1==d2){
        return d1;
    }
    /*
    //////for degug:
    else{
        cout<<"d1="<< d1<<endl;
        cout<<"d2="<< d2<<endl;
    }  
    */

}

void ugDriver::ini_visit(){
    //initialized visited array
    visited= new int[nodes-1];
    for(int i=0; i< nodes; i++){
        visited[i]=0;
    }
}

double ugDriver::shortest_d(int index1, int index2){

    ///assume name1 = start, name2=destination

    //////pre-setting

    /////need total number of cities 


        //set starting node with current cost= 0
        modi[index1].current_cost=0;

        undirectedGraph* eptr= &modi[index1];
        int ch=  eptr->connected_heapify.size();

        //assign nod 2 before running heapify
        for(int i=0; i< eptr->connected_h.size();i++){
        heap* checkptr= &eptr->connected_h[i];
        checkptr->nod2=i;
        checkptr= nullptr;
        }

        //for connected_h, we will copy the index to nod2
        eptr->connected_heapify=eptr->connected_h;

        //heapify array, since it's unordered, we need to heapify progressively.
        for(int i=1; i<eptr->connected_heapify.size()+1;i++){
            ///cout<<"i=" <<i<<endl;
        eptr->heapify(i);
        //eptr=nullptr;
        }

        ///////end of pre-setting


        /////debug
        /*
        for(int i=0; i< eptr->connected_heapify.size();i++){
        heap* checkptr= &eptr->connected_heapify[i];
        cout<< "connected_heapify["<< i<<"]="<< checkptr->dis<<endl; 
        checkptr= nullptr;
        }
        */

       ///now that each of the cities has its connected cities ordered by distance, so we need to pop the minimum out, 
       //replace the first index with the last one, then run heapify again. We also want to record the visited nodes/cities.

       //the priority heap works base upon 3 arrays, the first array keeps track of pervious node and current cost,
       //the second array uses min heap to determine the next city to be visited (this is determined by the min heap of each city and
       //as compared to all other cities globally)
       //the last array records the visited cities.

       //lastly, we check if the distination has been reached. once it's reached, we will stop the enitre function and return the cost.



       for(int i=0; i< modi.size(); i++){
           cout<< "mod["<< i<< "]="<< modi[i].current_cost<<endl;
       }

       cout<< "index1=" <<index1 <<endl;


       /////debug

        //print distance and connected nodes before running heapify
        for(int i=0; i< eptr->connected_heapify.size();i++){
        heap* checkptr= &eptr->connected_heapify[i];
        cout<< "heap* checkptr= &eptr->connected_heapify["<<i<<"]="<<  eptr->connected_heapify[i].dis<<endl;
       
        }


        relex(index1);
       for(int i=0; i< modi.size(); i++){
           cout<< "mod["<< i<< "]="<< modi[i].current_cost<<endl;
       }

         path= modi; 
        
       ///from path, pop out the visited nodes 

/*
        

       */

         for(int i=0; i< modi.size(); i++) {
             modi[i].current= i;
            cout<< "modi["<<i <<"]=" <<modi[i].current<<endl;
        }

        for(int i=0; i< modi.size();i++){
        path[i]=modi[i];
        }

        cout<< "initially"<<endl;
              for(int i=0; i< path.size(); i++) {
            cout<< "path_current["<<i <<"]=" <<path[i].current<<endl;
             cout<< "path_current cost["<<i<<"]=" <<path[i].current_cost<<endl;
        }

      
        for(int i=1; i< path.size()+1; i++){
           heap_path(i);
           }

           cout<<"after heap path" <<endl;

                    
        for(int i=0; i< path.size(); i++) {
           cout<< "path_current["<<i <<"]=" <<path[i].current<<endl;
            cout<< "path_current cost["<<i<<"]=" <<path[i].current_cost<<endl;

        }


       for(int i=0; i<modi.size(); i++){
           cout<< "visited["<<i<<"]="<< visited[i]<<endl;
        
       }

        int chk=path[0].current;
        while(visited[chk]==1){
           getmin();

           chk=path[0].current;
           for(int i=1; i< path.size()+1; i++){
           heap_path(i);
           }
           } 


           cout<<"after get min"<<endl;


        for(int i=0; i< path.size(); i++) {
         cout<< "path_current["<<i <<"]=" <<path[i].current<<endl;
           cout<< "path["<<i <<"]=" <<path[i].current_cost<<endl;
        }


                 for(int i=0; i< modi.size(); i++) {
             modi[i].current= i;
            cout<< "modi["<<i <<"]=" <<modi[i].current<<endl;
             cout<< "modi["<<i <<"].cost=" <<modi[i].current_cost<<endl;
        }

             cout<<"after relax"<<endl;



            relex(path[0].current);

            cout<<"after relax 1"<<endl;

         for(int i=0; i< modi.size(); i++) {
             modi[i].current= i;
            cout<< "modi["<<i <<"]=" <<modi[i].current<<endl;
             cout<< "modi["<<i <<"].cost=" <<modi[i].current_cost<<endl;
        }
           

         if(path[0].current_cost=INFINITY || modi[index2].current_cost!=INFINITY){
        //shortest_d(path[0].current,index2);
        return modi[index2].current_cost;
        }

        shortest_d(path[0].current,index2);



           return modi[index2].current_cost;

       //return modi[index2].current_cost;
        
       //sort path size   
       

    


}


void ugDriver::getmin(){

    //getting the minimum cost node from path

        int chk=path[0].current;
        //cout<<"chk"<<chk<<endl;
        if(visited[chk]==1){
            cout<<"1"<<endl;
           path[0]=path[path.size()-1];
           path.pop_back();
           for(int i=1; i< path.size()+1;i++){
                cout<<"2"<<endl;
                 heap_path(i);  
                 return;        
           }

            return;  

        }
        return;

}

//relexation of a city, updated global distance and parent if we fine a shorter distance
void ugDriver::relex(int in){

    visited[in]=1;

    cout<<"relex---------------"<<endl;

 

    //starting popping shortest distance out:
    undirectedGraph* eptr= &modi[in];
    //this will take the minimum out and run heapify
    cout<< "under relex, current node=" << eptr->current<<endl;
         for(int i=0; i<eptr->connected_h.size(); i++){
             cout<<"eptr->connected_h["<<i<<"].dis="<<eptr->connected_h[i].dis<<endl;
         }

        for(int i=0; i<eptr->connected_h.size();i++){
        eptr->connected_heapify.push_back(eptr->connected_h[i]);
         cout<<"eptr->connected_heapify["<<i<<"].dis="<<eptr->connected_heapify[i].dis<<endl;
      
    }

    //cout <<"eptr->connected_heapify.size()=" <<eptr->connected_heapify.size()<<endl;

    cout<<"1"<<endl;
    eptr->connected_heapify[eptr->connected_h.size()];

    cout<<"2"<<endl;


    for(int i=0; i<eptr->connected_heapify.size(); i++){

            cout<<"3"<<endl;

      //  cout<< "eptr->connected_heapify.size()="<< eptr->connected_heapify.size()<<endl;

        eptr->heapify(i);
          cout<<"4"<<endl;
        heap* hptr= &eptr->connected_heapify[i];
          cout<<"5"<<endl;
      //  cout<< "under relex, current node=" << eptr->current<<endl;
     //   cout<<"hptr->dis["<< i<<"]="<<hptr->dis<<endl;
     cout<<"6"<<endl;
        int d2= hptr->nod1;

        /////cout<< "&eptr->connected_heapify["<<i<<"]=" << hptr->dis<< endl;
        cout<<"7"<<endl;

         cout<< "modi[d2].current_cost="<<modi[d2].current_cost<<endl;
         cout<<"hptr->dis="<<eptr->connected_heapify[i].dis<<endl;
         cout<<"eptr->current_cos="<< eptr->current_cost<<endl;

        cout<< "hptr->dis+eptr->current_cost="<<hptr->dis+eptr->current_cost <<endl;
 
        cout<< "modi[d2].current_cost="<<modi[d2].current_cost<<endl;
        if(hptr->dis+eptr->current_cost<modi[d2].current_cost){
            cout<<"8"<<endl;
            modi[d2].current_cost=hptr->dis+eptr->current_cost;
            modi[d2].previous=in;
        }
        delete hptr;
        hptr=nullptr;

    }


        delete eptr;
       

        eptr=nullptr;
       
       cout<<"10"<<endl;

}

///make path copy modi and perform heap on path
void ugDriver::heap_path(int sizein){
    
  /*  
    for(int i=0; i< path.size(); i++) {
        cout<< "path["<<i <<"]=" <<path[i].current_cost<<endl;
    }
    */
    
   int asize=sizein-1;

   int asize_mod2= floor((asize)/2); 

    if(asize!=asize_mod2 &&asize>=0 ){
          if(path[asize].current_cost < path[asize_mod2].current_cost){
              undirectedGraph h1= path[asize_mod2];
              undirectedGraph h2=  path[asize];
              undirectedGraph temp;

              temp=h2;
              path[asize]=h1;
              path[asize_mod2]=temp;

              // swap(path[asize],path[asize_mod2]);
                heap_path(asize_mod2+1);
 
             }//end of if(asize-1>=0)

    }//end if((asize-1)/2>=0)

    return;



}




ugDriver::~ugDriver(){
    nodeptr=nullptr;
    delete nodeptr;
    }


