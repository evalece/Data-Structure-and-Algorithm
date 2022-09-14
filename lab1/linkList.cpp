/**
    ECE250
    linkList.h
    Purpose: provide enque and deque and other linklist functions. 
    Provides services to call array of type node and perform dynamic allocations.

    Author Eva Liu
    Version 1.0  - 27/01/2020
*/

#include <iostream>
#include "node.h"
#include "linkList.h"


using namespace std; 

/** 
 constructors 
 */
linkList::linkList(){

 node* current= nullptr; 
 node* head = nullptr; //head == the left most/ front of an array. 
 node* tail=nullptr;// the right most (back) of an array

}
linkList::~linkList() {

  node* current= nullptr; 
  node* head = nullptr; //head == the left most/ front of an array. 
  node* tail=nullptr;// the right most (back) of an array

 delete current;
 delete head; 
 delete tail; 


}

/**
prevent wild pointers when reassiging pointers
  Params: 
   target (in) - target pointer. 

 */


void linkList::cleanptr( node* target){
    target= nullptr;
    //delete target;
}

/**
 Add element at the front
   Params: 
   x (in) - number input (content).
 
*/
void linkList::enqueue_front (int x) {

    //size();
    if (arraysize==0) {
        cleanptr(current);
        current= new node(x);

        cleanptr(tail);
        tail=current; 
        arraysize=1;


        //setting up current member variables
        current -> prev = nullptr;
        current -> next = nullptr;

        cleanptr(head);
        head= current; 

    }

    else {

        arraysize++;
        cleanptr(current);
        current= new node(x);
        head->prev= current;
        current-> next= head; 
        current -> prev = nullptr;


        //update head
        cleanptr(head);
        head=current;

    }

    cout<< "success" << endl;



}

/**
 Add element at the end 
  Params: 
   x (in) - number input (content).
 */ 

void linkList::enqueue_back (int x) {
    if (arraysize==0) {
        cleanptr(current);
        current= new node(x);
        cleanptr(tail);
        tail= current; 
        cleanptr(head);
        head=current; 
        arraysize=1;


         //setting up current member variables
        current -> prev = nullptr;
        current -> next = nullptr;
    }

    else {
        arraysize++;
        cleanptr(current);
        current= new node(x);
        tail-> next= current;
        current-> prev= tail;
        current-> next=nullptr;

        //update head
        cleanptr(tail);
        tail= current;

    }


        cout<< "success" << endl;



    
}  

/**
Remove element from the front
*/
void linkList::dequeue_front() {

    if(arraysize!=0) {

     if (head->next!= nullptr) {
    head= head-> next; 
 
    // free the space taken by head
    head-> prev= nullptr; 

    //prevent current pointing at invailid space
    cleanptr(current);
    current= head;

    arraysize--;
    }

    else {
        deleteEle(head);
        deleteEle(current);
        deleteEle(tail);

        arraysize=0; 
    }


    cout<< "success" << endl;
  }
    //if the array is already empty;
  else {
      cout<< "failure" << endl;

  }

}

/**Remove element from the end
 */
void linkList::dequeue_back() {

//current pointing at the node before head

    if(arraysize!=0) {

    if (tail->prev!= nullptr) {
    tail= tail-> prev; 
 
    // free the space taken by head
    tail-> next= nullptr; 

    //prevent current pointing at invailid space
    cleanptr(current);
    current= tail;
    arraysize--;

    }

    else {
        deleteEle(head);
        deleteEle(current);
        deleteEle(tail);

        arraysize=0; 
    }


    cout<< "success" << endl;

    }
    //if the array is already empty;
    else {
      cout<< "failure" << endl;
        }


}

/**Clears the content of the deque if the queue is not already empty
 */
void linkList::clear(){
    //check current size.


        //clearing from the tail 
        while (arraysize!= 0){


            //copy of dequeue_back()


            if (tail->prev!= nullptr) {
            tail= tail-> prev; 
        
            // free the space taken by head
            tail-> next= nullptr; 

            //prevent current pointing at invailid space
            cleanptr(current);
            current= tail;
            }

            else {
                deleteEle(head);
                deleteEle(current);
                deleteEle(tail);

                arraysize=0; 
            }


        }

    cout<< "success" << endl;
    //update size after clear
}

/**
 Access the first element and compare to i, if equal, return success, else failure.
  Params: 
   iin (in) - number input (content).
 */
void linkList::front(int iin){
    if(head->number==iin){
        cout<<"success" <<endl;
    }

    else{
        cout<<"failure" <<endl;
    }


}

/**
 Access the last element and compare to i, if equal, return success, else failure
  Params: 
    iin (in) - number input (content).
 */
void linkList::back(int iin){
    if(tail->number==iin){
        cout<<"success" <<endl;
    }

    if(tail->number!=iin){
        cout<<"failure" <<endl;
    }

}

/**
 Test if deque is empty
 */
void linkList::empty() {
    //size();
    if(arraysize==0) {
       cout<<"success" <<endl;
    }
    else {
     cout<<"failure" <<endl;   
    }


}

/**
 Print all the values in the deque two times: • from front to back • from back to front
 */
void linkList::print() {
        
        //size();

        // only print when there are contents 
        if (arraysize!=0) {
        cleanptr(current); 
        //print front to back first
        current= head; 
        while (current!= nullptr && arraysize!=0) {
    

        cout<< current->number;
        current= current->next;

        //no space input if there is no next number   
        if(current != nullptr) {
            cout<< " ";
        }
        
   

        }

        cout<< endl;  

        cleanptr(current); 
        //print back to front 
        current= tail; 
        while (current!= nullptr && arraysize!=0 && arraysize!=1 ) {
        cout<< current->number;


        //no space input if there is no next number 
        current= current->prev;
        if(current != nullptr) {
        cout<< " ";
            }  

        }

         cout<< endl;
    }
    

}

/**
 delete element pointed by the pointer and free the space
  Params: 
   target (in) - target pointer. 

 */
void linkList::deleteEle (node* target){
    target = nullptr; 
    delete target; 

}


/**
 counting the size of the array
 */
void linkList::size() {


        cout<<"size is "<< arraysize << endl;

    //setting current node to the beginning of the array (leftmost) and count as long as next elemet exist.

    /*
    if (arraysize!=0){

     //setting arraysize = 0 to recount
     arraysize=0;
 
        current = head; 
        while (current!=nullptr){
            arraysize++;
            current=current->next;
      
        }

    }


    */

}








