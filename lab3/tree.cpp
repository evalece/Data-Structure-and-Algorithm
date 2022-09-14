/**
    ECE250
    tree.cpp
    Purpose: provide functions for a tree of node based on user inputs.
    Provides services to call array of type node and perform dynamic allocations.

    Author Eva Liu ID:20724405 UWID:lj2liu
    Version 4.5 - 12/03/2020
*/

#include <iostream>
#include "node.h"
#include "tree.h"


using namespace std; 

/** 
 constructors and destructors
 */
tree::tree(){

    root= nullptr; 
    target= nullptr;
    max=0;
    total=0;
    min=0;
}


tree::~tree() {

    root= nullptr; 
    delete root;

}

    
/**
allocate a new node for inserting.

Params:
 nn string (in)- city name
 xx double (in)- x coordinate
 yy double (in) -y coordinate
 pp int (in)-populaion
 rr int (in)- living cost
 ss int (in)- average salary
   
*/
void tree::forinsert(string nn, double xx, double yy, int pp, int rr, int ss) {
        toInsert= new node(nn,xx,yy,pp,rr,ss);
}



/**
allocate the space in the tree for a new node for inserting.

Params:
p node*  (in)- the root of the tree
i node*  (in)- the inserting node 
  
*/
bool tree::insert(node* p, node* i) {


  //node* p is assign to root on the first call. 
  bool inserted= false;
    

    // assign root if nothing exists
    if(p==nullptr) {
  
        p=i;

        //assign the first inserted node as root
        root=i;

        bool inserted=true;
        cout<< "success" <<endl;
        size++;
        return inserted;
        }
 
    if (inserted ==false) {


        //the following recursive call will insert curren node into leave nodes. 
       
            //the following is recurrsion for placing direction

            //////////ne direction

            if(i->x>= p->x && i->y > p->y) {

  

                 //if the space is taken, make the node (currently taking the space) the new parent and try insert current below it by calling the recursive call.
                if(p->ne!=nullptr){
                //reset variable for recursive call
      
                insert(p->ne, toInsert);
                }   

                //insert current node to the corresponding direction of the current node if the parent has an empty space (direction pointer) to place it.
                if(p->ne==nullptr){

                    p->ne=toInsert; 
                     inserted=true;
                } 
               
            }


            //////////nw direction
            if(i->x < p->x && i->y >= p->y ) {
                // cout<<"2"<<endl;

                 //if the space is taken, make the node (currently taking the space) the new parent and try insert current below it by calling the recursive call.
                if(p->nw!=nullptr){
                //reset variable for recursive call
                insert(p->nw, toInsert);
                }   

                //insert current node to the corresponding direction of the current node if the parent has an empty space (direction pointer) to place it.
                if(p->nw==nullptr){
                    p->nw=toInsert;  
                     inserted=true;
 
                } 
               
            } //end of nw


            //////////sw direction
            if(i->x <= p->x   && i->y < p->y) {
                //           cout<<"3"<<endl;

                //if the space is taken, make the node (currently taking the space) the new parent and try insert current below it by calling the recursive call.
                if(p->sw!=nullptr){
                //reset variable for recursive call
                insert(p->sw, toInsert);
                } 


                //insert current node to the corresponding direction of the current node if the parent has an empty space (direction pointer) to place it.
                if(p->sw==nullptr){
                    p->sw=toInsert; 
                     inserted=true; 

                } 
             
            } //end of sw 


            //////////se direction
            if(i->x > p->x  && i->y <=p->y) {
                 //          cout<<"4"<<endl;
                //if the space is taken, make the node (currently taking the space) the new parent and try insert current below it by calling the recursive call.
                if(p->se!=nullptr){
               //   cout<<"5"<<endl;
                //reset variable for recursive call
                insert(p->se, toInsert);
                } 

                //insert current node to the corresponding direction of the current node if the parent has an empty space (direction pointer) to place it.
                if(p->se==nullptr){
                    p->se=toInsert;
                    inserted=true;
                } 
                 
            }//end of se

            //duplicate case
            if(i->x == p->x   && i->y == p->y) {
                cout<<"failure" <<endl;
            } 


        }//end of inserted= false

        //insertion is complete, now exit the loop

        if(inserted==true) {
            size++;
            cout<< "success"<<endl;
        }


        cleanptr(i);
        cleanptr(p);


        return inserted; 
       



}
 

 /**
printing the entire tree in inorder traversal.

Params:
rootp node*  (in)- the root of the tree. 
*/
void tree::print(node* rootp){

    //using in order travel: left-> node -> right. we use ne, nw node sw se here. 
 
        if(rootp==nullptr || size==0) {
            return;
        }
        //recursively call and using stack:
        
        print(rootp->ne);
       
        print(rootp->nw);
       
        cout<< rootp->name <<" ";;

        print(rootp->sw);       
   
        print(rootp->se);

        return;


}

 /**
search and return a pointer the node having the same position.

Params:
p node*  (in)- the root of the tree (or a root of a recursion).
i node*  (in)- the checking node  (a node containing position info).
*/
void tree::search(node* p, node* i){

    //recusrively searching for the spot where the inserted city shares the same coordinate as the input. 
    // if the node has next suggesting search node == nullptr, that means we don't find the corresponding city. 
    //similar to insert except we are not looking for an empty space to insert nodes in, we are only following the insertion path to find the corresponding city.

        bool resolved= false;

    // if no root exist
    if(p==nullptr) {

        cout<< "not found" <<endl;
        resolved=true;
        return;
        }
    
    //recursive check: of the current node is the match
      if(p->x==i->x && p->y==i->y) {

        cout<< "found "<< p->name<<endl;
        resolved=true;
        return ;
        }


    //the following is a recursive call to the direction and order of inserting. note the current node is not nullptr. 
 
    if (resolved ==false) {

        //the following recursive call will insert current node into leave nodes.      
        //the following is recurrsion for placing direction

            //////////ne direction
            if(i->x>= p->x && i->y > p->y) {
                //comparing with the direction node (regardless if it's a nullptr or not)
                search(p->ne,i);
               
            }


            //////////nw direction
                if(i->x < p->x && i->y>= p->y ) {

                //comparing with the direction node (regardless if it's a nullptr or not)
                search(p->nw,i);
            }


            //////////sw direction
                if(i->x <= p->x   && i->y < p->y) {
                 //comparing with the direction node (regardless if it's a nullptr or not)
                search(p->sw,i);
               
            }

            //////////se direction
                if(i->x > p->x  && i->y <=p->y) {
                 //comparing with the direction node (regardless if it's a nullptr or not)
                search(p->se,i);
               
            }


        }//end of resolved= false

        //insertion is complete, now exit the loop
        cleanptr(p);
        cleanptr(i);

        return; 

}


/**
search and return a pointer the node having the same position.

Params:
p node*  (in)- the root of the tree (or a root of a recursion).
i node*  (in)- the checking node  (a node containing position info).

returns a node in the tree that has the same postion info. 
*/
node* tree::searchnode(node* p, node* i){

    //recusrively searching for the spot where the inserted city shares the same coordinate as the input. 
    // if the node has next suggesting search node == nullptr, that means we don't find the corresponding city. 
    //similar to insert except we are not looking for an empty space to insert nodes in, we are only following the insertion path to find the corresponding city.


        bool resolved= false;
        //start with a new pointer, a nullptr.
        cleanptr(target);

    // if no root exist
    if(p==nullptr) {
        resolved=true;
        return target;
        }
    
    //recursive check: of the current node is the match
      if(p->x==i->x && p->y==i->y) {
        //found the corresponding city
        target=p; 
        resolved=true;
        return target ;
        }

    //the following is a recursive call to the direction and order of inserting. note the current node is not nullptr. 
    if (resolved ==false) {
        //the following recursive call will insert current node into leave nodes.      
        //the following is recurrsion for placing direction

            //////////ne direction
            if(i->x>= p->x && i->y > p->y) {
                //comparing with the direction node (regardless if it's a nullptr or not)
                searchnode(p->ne,i);
               
            }

            //////////nw direction
                if(i->x < p->x && i->y>= p->y ) {

                //comparing with the direction node (regardless if it's a nullptr or not)
                searchnode(p->nw,i);
            }

            //////////sw direction
                if(i->x <= p->x   && i->y < p->y) {
                 //comparing with the direction node (regardless if it's a nullptr or not)
                searchnode(p->sw,i);
               
            }
            //////////se direction
                if(i->x > p->x  && i->y <=p->y) {
                 //comparing with the direction node (regardless if it's a nullptr or not)
                searchnode(p->se,i);
               
            }

        }//end of resolved= false

        //insertion is complete, now exit the loop

        //it's possible that target is a nullptr.
        return target; 

}

 /**
q_max returns the maximum value in diretion d on criteria attr: p, r, s

Params:
rootp node*  (in)- the root of the tree (or a root of a recursion).
attr string  (in)- the attribute of the city.
*/
void tree::q_max(node* rootp, string attr) {


        //for attr= r 

        if(attr=="r") {
  
        if(rootp==nullptr) {

            return;   
        }

        if(rootp!=nullptr) {
            if(max<rootp->r) {


                //let r overwrite the global variable max
                max=rootp->r;
            }

        }

        //recursively call and using stack:
       
        q_max(rootp->ne, attr);
    
        q_max(rootp->nw,attr);
    
        q_max(rootp->sw,attr);
       
        q_max(rootp->se,attr);

        return;

     }



        if(attr=="p") {
  
        if(rootp==nullptr) {
            return;   
        }

        if(rootp!=nullptr) {
            if(max<rootp->p) {

                //let r overwrite the global variable max
                max=rootp->p;
            }

        }

        //recursively call and using stack:
       
        q_max(rootp->ne, attr);
    
        q_max(rootp->nw,attr);
    
        q_max(rootp->sw,attr);
       
        q_max(rootp->se,attr);

        return;

     }


        if(attr=="s") {
  
        if(rootp==nullptr) {
            return;   
        }

        if(rootp!=nullptr) {
            if(max<rootp->s) {

                //let r overwrite the global variable max
                max=rootp->s;
            }

        }

        //recursively call and using stack:
       
        q_max(rootp->ne, attr);
    
        q_max(rootp->nw,attr);
    
        q_max(rootp->sw,attr);
       
        q_max(rootp->se,attr);

        return;

     }

}


 /**
q_min returns the min value in diretion d on criteria attr: p, r, s

Params:
rootp node*  (in)- the root of the tree (or a root of a recursion).
attr string  (in)- the attribute of the city.
*/
void tree::q_min(node* rootp, string attr) {


        //for attr= r 

        if(attr=="r") {
  
        if(rootp==nullptr) {

            return;   
        }

        if(rootp!=nullptr) {
            if(min>rootp->r) {


                //let r overwrite the global variable max
                min=rootp->r;
            }

        }

        //recursively call and using stack:
       
        q_min(rootp->ne, attr);
    
        q_min(rootp->nw,attr);
    
        q_min(rootp->sw,attr);
       
        q_min(rootp->se,attr);

        return;

     }



        if(attr=="p") {
  
        if(rootp==nullptr) {
            return;   
        }

        if(rootp!=nullptr) {
            if(min>rootp->p) {

                //let r overwrite the global variable max
                min=rootp->p;
            }

        }

        //recursively call and using stack:
       
        q_min(rootp->ne, attr);
    
        q_min(rootp->nw,attr);
    
        q_min(rootp->sw,attr);
       
        q_min(rootp->se,attr);

        return;

     }


        if(attr=="s") {
  
        if(rootp==nullptr) {
            return;   
        }

        if(rootp!=nullptr) {
            if(min>rootp->s) {

                //let r overwrite the global variable max
                min=rootp->s;
            }

        }

        //recursively call and using stack:
       
        q_min(rootp->ne, attr);
    
        q_min(rootp->nw,attr);
    
        q_min(rootp->sw,attr);
       
        q_min(rootp->se,attr);

        return;

     }

}

 /**
q_total returns the sum value in diretion d on criteria attr: p, r, s

Params:
rootp node*  (in)- the root of the tree (or a root of a recursion).
attr string  (in)- the attribute of the city.
*/
void tree::q_total(node* rootp, string attr) {
      //for attr= r 

        //for attr= r 

        if(attr=="r") {
  
        if(rootp==nullptr) {

            return;   
        }

        if(rootp!=nullptr) {
            

                //sum total with recursion
                total= total+rootp->r;
            

        }

        //recursively call and using stack:
       
        q_total(rootp->ne, attr);
    
        q_total(rootp->nw,attr);
    
        q_total(rootp->sw,attr);
       
        q_total(rootp->se,attr);

        return;

     }



        if(attr=="p") {
  
        if(rootp==nullptr) {
            return;   
        }

        if(rootp!=nullptr) {
         
                //sum total with recursion
                total= total+rootp->p;

        }

        //recursively call and using stack:
       
        q_total(rootp->ne, attr);
    
        q_total(rootp->nw,attr);
    
        q_total(rootp->sw,attr);
       
        q_total(rootp->se,attr);

        return;

     }


        if(attr=="s") {
  
        if(rootp==nullptr) {
            return;   
        }

        if(rootp!=nullptr) {
 
                //sum total with recursion
                total= total+rootp->s;
        }

        //recursively call and using stack:
       
        q_total(rootp->ne, attr);
    
        q_total(rootp->nw,attr);
    
        q_total(rootp->sw,attr);
       
        q_total(rootp->se,attr);

        return;

     }


}


 /**
like print, delete visits every node and delete (aka clean pointer) for each of them

Params:
a node*  (in)- the root of the tree (or a root of a recursion).
*/
void tree::clear(node* a){

 //do nothing if size is already 0 

 if(size==0) {
     return;
 }


  //using in order travel: left-> node -> right. we use ne, nw node sw se here. 

        if(a->ne!=nullptr){
            clear(a->ne);
        }

        if(a->nw!=nullptr){
            clear(a->nw);
        }

        if(a->sw!=nullptr){
            clear(a->sw);
        }

        if(a->se!=nullptr){
            clear(a->se);
        }

       // cout<< "delete node " << a->name <<endl;
        size--;

         todel=a;

          // cout<< "delete node todel " << todel->name <<endl;
         todel=nullptr;
         delete a; 

}

 /**
a short cut for assigning nullptr and delete pointer of type node.

Params:
c node*  (in)- the root of the tree (or a root of a recursion).
*/
void tree::cleanptr(node* c){

    c= nullptr;
    delete c;
 

}
