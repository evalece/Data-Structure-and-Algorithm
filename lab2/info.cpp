#include <iostream>
using namespace std; 

#include "info.h"

info::info(long numin, string userin){
    phone=numin;
    user=userin;

    //setting nullptr one more time
    info* prev =nullptr; 
    info* next=nullptr;

}

//default constructor

info::info(){


    phone=0;
    user="0";

    //setting nullptr one more time
    info* prev =nullptr; 
    info* next=nullptr;
    

}

//copy constructor
 info::info(const info &p2) { 
     phone = p2.phone; 
     user = p2.user;   

      info* prev= p2.prev;
      info* next= p2.next;


     } 


info::~info(){
    info* head =nullptr; 
    delete head;
    info* tail=nullptr;
    delete tail;
    int* headint=nullptr;
    delete headint;

}