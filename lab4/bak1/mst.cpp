/**
    ECE250
   mst.cpp

   the mst by the Greedy Method sorts each input nodes (one node contains the edge weight and the two vertices that forms it) from minimum weight cost
   to maximum weight cost. 

   A disjoing set (essentially an array, see #1 for more detail) helps tracking cycyles and disconections when mst total weight is called. 

    let n be the number of initilized vertex.
   #1 O(n):An array of int type. It stores parent and child info. Inititialize array with -1, minus means the node is a parent, 1 means the number of 
   vertices in the subtree. The child node index store the parent node number. A recursive call "find parent" is applied to find the ultimate parent 
   with the largest 

   #2: another array is to check the edge degree upon each input: an array size is n. Initialize all to 0. Upon each edge input, the parent and child vertex
   index is increamented by 1 per insertion. 
   

    Author Eva Liu ID:20724405 UWID:lj2liu
    Version 2.0  - 31/03/2020
*/

#include <iostream>
#include <vector>       // std::vector
#include <algorithm>    // std::sort
#include "node.h"
#include "mst.h"



using namespace std; 

/** 
 constructors and destructors
 */

mst::mst(){
    //do nothing
    }

mst::mst(int m_in){
    
    //initilize vertex # 
    m=m_in;

    //initialize on check array 
    for(int i=0; i<m; i++){

        check.push_back(-1);

        /*degug
        cout<< "check index " << i << ":"<< check[i]<<endl;
        */
    }

    //index is node number
    vertex_count= new int[m];

    for(int i=0; i<m; i++){
    //initialize all as 0.
        vertex_count[i]=0;
    }

 
}// end of constructor


//copy constructor
mst::mst(mst const &cp){
    m=cp.m;

}


/////////////////////////first part of functionality: insertion of nodes, delete and sort them when needed. 

void mst::insert(int parent_in, int child_in, double weight_in){

    bool replace=false;

    //insertion first check if an edge already exist O(m), m= net.size().

    int i= 0;

    while(replace== false &&  i< net.size()) {

        //a delete target is found 
        if(net[i].parent==parent_in && net[i].child==child_in) {
            replace=true;
            //update weight, don't push_back.
            net[i].weight=weight_in;    
        }
        i++;
    }

    //if this is a new edge
    if(replace==false){
        node* in= new node(parent_in,child_in,weight_in);
        //node insertion
        net.push_back (*in);

        cleanptr(in);
     }


        vertex_count[parent_in]=1;
        vertex_count[child_in]=1;

}//end of insertion

void mst::cleanptr(node* target){
    target=nullptr;
    delete target;
}//end of cleanptr


mst::~mst() {

}//end of ~mst


//sorting net array, from minimum to maximum
void mst::sortnet(){

sort(net.begin(), net.end(), [](node a, node b){

    return a.weight<b.weight;

    });

    //debug, checking sort result


    /*
    
    for(node netresult: net ){
        

        cout<<"weight="<< netresult.weight<<endl;
        cout<< "parent=" << netresult.parent<<endl;
        cout<< "child=" << netresult.child<<endl;

    }
    */
    
}//end of sort net


//delete an edge 
bool mst::del(int parent_in, int child_in){
    
    bool found =false;
    int i=0;

    while(found== false &&  i< net.size()) {

        //a delete target is found 
        if(net[i].parent==parent_in && net[i].child==child_in) {
            found=true;


            //delete and re-index net; use the last node to replace the deleted node, then pop back:
            net[i]=net[net.size()];
            net.pop_back();          
        }

        i++;

    }

    return found;

}


//checking the degree of the node v by looping through the net work, the output is the original network vertex degree
int mst::degreev(int v){

    //degree track
    int deg =0;

    //looping throgh to count vertex v as either child or parent
  

    //insertion first check if an edge already exist O(m), m= net.size().

    int i= 0;

    while(i< net.size()) {
        //a delete target is found 
        if(net[i].parent==v || net[i].child==v) {
            deg++;   
        }
        i++;
    }

    return deg;
}


////////////////////////////////////////second part of the functionality


//for check array, call this after sort
int mst::findparent(const int a){

    int b=a;

    //recursion 

    //if the current node 
    if(check[b]>=0){
        b=check[b];
        findparent(check[b]);
    }
    
   // cout<< "recursion returning b=" <<b <<endl;
    return b;
    
}



void mst::mintree(){  

    //sorting first 
    sortnet();
    //min is the accumulate edge weight. Accumulation m-1 times at most.
    int min=0;
    //determine ver-1 using vertex_count, aka accounting initialized vertex
    int ver=0; 
 cout<<"*1"<<endl;
    //counting initilzed vertices
    for(int i=0; i<m; i++){
        if(vertex_count[i]==1){
            ver++;
             cout<<"*2"<<endl;

        }

        cout<<"*3"<<endl;
        cout<<"ver"<< ver<<endl;
    }

    //i is the total number of edges that has been counted by min tree
    int i=0;
 cout<<"*4"<<endl;
    //loop for counting min tree is at most i=m-1
     while(i<ver){
 cout<<"*5"<<endl;
         //recursively solve for parent for disjoint set. Skip edges that cause cycles(i.e two node having the same untimate parent)
         int pp=findparent(net[i].parent);
         int pc=findparent(net[i].child);
    
    //update check based on the following cases


    //case 1:  both positive --- recursively solve the ultimate parent. Assign the new ultimate parent

    if(check[net[i].parent]>-1 &&check[net[i].child] >-1){
        //both net[i].parent and net[i].child are child of other vertices, so check their ultimate parent and assign to their check[];
        check[net[i].parent]=pp;
        check[net[i].child]=pc;
        
        //pc is the more negative parent
        if(check[pc]<check[pp]){
            
        } 

        

    }

    //case 2: both negative
    // but one is more negative than the other ---treat the more negative one as parent. //&& removal of check[net[i].parent]!=check[net[i].child] condition 
    //to cover old 2-2
    if(check[net[i].parent]<= -1 && check[net[i].child] <= -1 ) {
        //2-1
        if(check[net[i].parent]<check[net[i].child]) {
            //ie. if check[parent] = -2, check[chiild]=-1 then, check[parent]=-3, check[child]=parent;
            check[net[i].parent]=check[net[i].child]+check[net[i].parent]; //-1+ (-2)=-3
            check[net[i].child]=net[i].parent;  // check[child]=parent  

                 cout<<"*8"<<endl;       
        }

        //2-2
        if(check[net[i].parent]>check[net[i].child]) {
            //ie. if check[parent] = -1, check[chiild]=-2 then, check[child]=-3, check[parent]=child;
            check[net[i].child]=check[net[i].child]+check[net[i].parent]; //-1+ (-2)=-3
            check[net[i].parent]=net[i].child;         //check[parent]=child 

                 cout<<"*7"<<endl;  
        }

        //2-3
        if(check[net[i].parent]==check[net[i].child]) {
            //unconditionally make current parent as ultimate parent.
            check[net[i].parent]=check[net[i].child]+check[net[i].parent]; //-1+ (-2)=-3
            check[net[i].child]=net[i].parent;  // check[child]=parent 

             cout<<"*6"<<endl;    
        }


    }//end of case 2

/*

    //old 2-2 haveing both are negative but -m=-n---- Treat smaller vertex# as parent.
          if(check[net[i].parent]==check[net[i].child] & check[net[i].child]<0) {
            //ie. if check[parent] = -1, check[chiild]=-2 then, check[child]=-3, check[parent]=child;
            check[net[i].parent]=check[net[i].child]+check[net[i].parent]; //-1+ (-2)=-3
            check[net[i].child]=net[i].parent;  // check[child]=parent    
        }
*/

    


    //case3: one negative one positve--- treat the negative one as parent.
    if(check[net[i].child]* check[net[i].parent] <0) {
        bool dealt=false;

        //let the negative one be the ultimate parent.
        if(check[net[i].child]<check[net[i].parent] && dealt==false){
             //ie. if check[parent] = 1, check[chiild]=-2 then, check[child]=-3, check[parent]=child;
            check[net[i].child]=check[net[i].child]--; //-2+ (-1)=-3
            check[net[i].parent]=net[i].child;         //check[parent]=child 
            dealt=true;

        }
        

        if(check[net[i].child]>check[net[i].parent] &&dealt==false){
            //ie. if check[parent] = -2, check[chiild]=1 then, check[parent]=-3, check[child]=parent;
            check[net[i].parent]=check[net[i].parent]--; //(-2)-1=-3
            
            check[net[i].child]=net[i].parent;  // check[child]=parent  
            dealt=true;
        }



    
    }//end of case 3




    //check next element 
    i++;


  }//end of while




    
    
}//end of mintree





    


