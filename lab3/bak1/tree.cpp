/**
    ECE250
    tree.h
    Purpose: provide enque and deque and other tree functions. 
    Provides services to call array of type node and perform dynamic allocations.

    Author Eva Liu
    Version 1.0  - 27/01/2020
*/

#include <iostream>
#include "node.h"
#include "tree.h"


using namespace std; 

/** 
 constructors 
 */
tree::tree(){

    root= nullptr; 
}


tree::~tree() {

root= nullptr; 
delete root;

}

void tree::forinsert(string nn, float xx, float yy, int pp, float rr, float ss) {
        toInsert= new node(nn,xx,yy,pp,rr,ss);

        cout<< "toInsert->x" << toInsert->x <<endl;
}

void tree::insert(node *& p, node *&i) {

cout<<  " i->x" <<i->x << endl;

//   //node* p is assign to root on the first call. 
//   bool inserted= false;
    

//     // assign root if nothing exists
//     if(p==nullptr) {

//         cout<<"0.1"<<endl;
//         p=i;

//         bool inserted=true;
//         return;
//         }
 
//     if (inserted ==false) {


//         //the following recursive call will insert curren node into leave nodes. 
       
//             //the following is recurrsion for placing direction

//             cout<<"1"<<endl;

//             //////////ne direction

//             cout<<  " i->x" <<i->x << endl;
//              cout<<  " p->x" <<p->x << endl;
//             if(i->x> p->x || i->x== p->x && i->y > p->y) {

//                    cout<<"1.1"<<endl;

//                  //if the space is taken, make the node (currently taking the space) the new parent and try insert current below it by calling the recursive call.
//                 if(p->ne!=nullptr){
//                 //reset variable for recursive call
//                    cout<<"1.2"<<endl;
//                 insert(p->ne, toInsert);
//                 }   

//                 //insert current node to the corresponding direction of the current node if the parent has an empty space (direction pointer) to place it.
//                 if(p->ne==nullptr){
//                        cout<<"1.3"<<endl;
//                     p->ne=toInsert; 
//                      inserted=true;
//                 } 
               
//             }


//             //////////nw direction
//             if(i->x < p->x && i->y > p->y || i->y == p->y) {
//                  cout<<"2"<<endl;

//                  //if the space is taken, make the node (currently taking the space) the new parent and try insert current below it by calling the recursive call.
//                 if(p->nw!=nullptr){
//                 //reset variable for recursive call
//                 insert(p->nw, toInsert);
//                 }   

//                 //insert current node to the corresponding direction of the current node if the parent has an empty space (direction pointer) to place it.
//                 if(p->nw==nullptr){
//                     p->nw=toInsert;  
//                      inserted=true;
 
//                 } 
               
//             } //end of nw


//             //////////sw direction
//             if(i->x < p->x || i->x == p->x  && i->y < p->y) {
//                            cout<<"3"<<endl;

//                 //if the space is taken, make the node (currently taking the space) the new parent and try insert current below it by calling the recursive call.
//                 if(p->sw!=nullptr){
//                 //reset variable for recursive call
//                 insert(p->sw, toInsert);
//                 } 


//                 //insert current node to the corresponding direction of the current node if the parent has an empty space (direction pointer) to place it.
//                 if(p->sw==nullptr){
//                     p->sw=toInsert; 
//                      inserted=true; 

//                 } 
             
//             } //end of sw 


//             //////////se direction
//             if(i->x > p->x  && i->y < p->y || i->y == p->y ) {
//                            cout<<"4"<<endl;
//                 //if the space is taken, make the node (currently taking the space) the new parent and try insert current below it by calling the recursive call.
//                 if(p->se!=nullptr){
//                   cout<<"5"<<endl;
//                 //reset variable for recursive call
//                 insert(p->se, toInsert);
//                 } 

//                 //insert current node to the corresponding direction of the current node if the parent has an empty space (direction pointer) to place it.
//                 if(p->se==nullptr){
//                     p->se=toInsert;
//                     inserted=true;
//                 } 
                 
//             }//end of se


//         }//end of inserted= false

//         //insertion is complete, now exit the loop


            
//         cleanptr(p);
//         cout<< "current name : " << i->name<<endl;
//         cleanptr(i);


}
 
void tree::print(node* rootp){

    //using in order travel: left-> node -> right. we use ne, nw node sw se here. 

    cout<<"p 1" <<endl;
  //cout<< rootp->name << " ";
        if(rootp==nullptr) {
            cout<<"p 1.1" <<endl;
               cleanptr(rootp);
            return;
 
        }

        //recursively call and using stack:
       
       
        cout<<"p 1.2" <<endl;
        print(rootp->ne);
    
       
        cout<<"p 1.3" <<endl;
        print(rootp->nw);
     

        cout<< rootp->name << " ";

    
        cout<<"p 1.4" <<endl;
        print(rootp->sw);
      

    
        cout<<"p 1.5" <<endl;
        print(rootp->se);
        

}


void tree::cleanptr(node* c){

    c= nullptr;
    delete c;

}
