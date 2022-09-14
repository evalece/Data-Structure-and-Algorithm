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



void tree::insert(string nn, float xx, float yy, int pp, float rr, float ss) {

    bool inserted= false; 
    node* current= new node(nn,xx,yy,pp,rr,ss);

    // assign root if nothing exists
    if(root==nullptr) {

    cout<<"0.1"<<endl;
    root= current;
    inserted= true;

    }

         cout<<"0"<<endl;

        node* parent = root;//start comparing with root
        //the following recursive call will insert curren node into leave nodes. 
        while(inserted==false){
            //the following is recurrsion for placing direction

            cout<<"1"<<endl;

            //////////ne direction
            if(current->x> parent->x || current->x== parent->x && current->y > parent->y) {
                //insert current node to the corresponding direction of the current node if the parent has an empty space (direction pointer) to place it.
                if(parent->ne==nullptr){
                    parent->ne=current; 

                    //a tag to quit recusrive call
                    inserted= true;
                } 
                //if the space is taken, make the node (currently taking the space) the new parent and try insert current below it by calling the recursive call.
                if(parent->ne!=nullptr){
                //reset variable for recursive call
                parent= parent->ne;
                }                  
            }


            //////////nw direction
            if(current->x < parent->x && current->y > parent->y || current->y == parent->y) {
                           cout<<"2"<<endl;
                //insert current node to the corresponding direction of the current node if the parent has an empty space (direction pointer) to place it.
                if(parent->nw==nullptr){
                    parent->nw=current; 
 

                    //a tag to quit recusrive call
                    inserted= true;
                } 
                //if the space is taken, make the node (currently taking the space) the new parent and try insert current below it by calling the recursive call.
                if(parent->nw!=nullptr){
                //reset variable for recursive call
                parent= parent->nw;
                }                  
            } //end of nw


            //////////sw direction
            if(current->x < parent->x || current->x == parent->x  && current->y < parent->y) {
                           cout<<"3"<<endl;
                //insert current node to the corresponding direction of the current node if the parent has an empty space (direction pointer) to place it.
                if(parent->sw==nullptr){
                    parent->sw=current; 

                    //a tag to quit recusrive call
                    inserted= true;
                } 
                //if the space is taken, make the node (currently taking the space) the new parent and try insert current below it by calling the recursive call.
                if(parent->sw!=nullptr){
                //reset variable for recursive call
                parent= parent->sw;
                }                  
            } //end of sw 


            //////////se direction
            if(current->x > parent->x  && current->y < parent->y || current->y == parent->y ) {
                           cout<<"4"<<endl;
                //insert current node to the corresponding direction of the current node if the parent has an empty space (direction pointer) to place it.
                if(parent->se==nullptr){
                    parent->se=current; 

                    //a tag to quit recusrive call
                    inserted= true;
                } 
                //if the space is taken, make the node (currently taking the space) the new parent and try insert current below it by calling the recursive call.
                if(parent->se!=nullptr){
                               cout<<"5"<<endl;
                //reset variable for recursive call
                parent= parent->se;
                }                  
            }//end of se


        }//end of while loop

        //insertion is complete, now exit the loop

        if(inserted==true) {
            size++;
        }
            
        cleanptr(parent); 

        cout<< "current name : " << current->name<<endl;
        cleanptr(current);


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
