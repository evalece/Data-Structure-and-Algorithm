#include <iostream>
#include "hasht.h"
//constructor and destructor
hasht::hasht(){
    //intialize the vector with size 0
    hashtv.resize(0);
    inserttrack=0;
}

hasht::~hasht(){
}

void hasht::resizeinfo(long sizein){
    size =sizein;
    //intialize the vector with all entries=0
    hashtv.resize(sizein);
}


void hasht::dhinsert(long numin, string user){

    long x= numin % size;
    bool found= false;
    //primary hasing 
    if(hashtv[x].phone==0) {
        hashtv[x].phone=numin;
        hashtv[x].user=user; 
        found=true;
    }
    else{
        long y= (numin/size) % size;
        if(y%2==0){
            y++;
        }
        //looping double hashing to find empty space.
        while(hashtv[y].phone!=0 && inserttrack<size+1){
            //repeating double hashing assignment
            y= (y/size) % size;
            if(y%2==0){
            y++;
        }
        if(hashtv[y].phone==0 && found==false){

            hashtv[y].phone=numin;
            hashtv[y].user=user;
            found=true;

        }

    }

    if(found==true) {
        cout<<"success" << endl;
        //increment size tracking
        inserttrack++;
    }

    //failure when 1 no space in hash table or 2 a repeated number is found
    else{
        cout<<"failure"<<endl;
    }

    }

}

void hasht::dhdelete(long numin){

    long x= numin % size;
    bool found= false;
    long k = numin;
    //primary hasing 
    if(hashtv[x].phone==k) {
        hashtv[x].phone=0;
        hashtv[x].user="0"; 
        found=true;

    }
    else{

        long y= (numin/size) % size;
        if(y%2==0){
            y++;
        }
        //looping double hashing to find empty space.
        while(hashtv[y].phone==k && found==false){
            //repeating double hashing assignment
            y= (y/size) % size;
            if(y%2==0){
            y++;
        }

        if(hashtv[y].phone==0){

            //assigning it back to 0 for no such number

            hashtv[y].phone=0;
            hashtv[y].user="0";
            found=true;

        }

    }

    if(found==true) {
        cout<<"success" << endl;
        //decreament tracking size
        inserttrack--;
    }
    else{
        cout<<"failure"<<endl;
    }

    }
}

void hasht::searchdh(long k){

    //using the same way as insertion for searching.
    long x= k % size;
    bool found= false;
    //primary hasing 
    if(hashtv[x].phone==k ) {
        found=true;
         cout<<"found "<<hashtv[x].user<<" in "<< x<<endl;

    }
    else{

        long y= (k/size) % size;
        if(y%2==0){
            y++;
        }
        //looping double hashing to find empty space.
        while(hashtv[y].phone==k){
            //repeating double hashing assignment
            y= (y/size) % size;
            if(y%2==0){
            y++;
        }

        if(hashtv[y].phone==k && found==false){
        found=true;
        cout<<"found "<<hashtv[y].user<<" in "<< x<<endl;

        }

    }

    if(found==false) {
      cout<<"failure"<<endl;
    }
}
}

//double hashing
void hasht::chaininsert(long numin, string user){
     long x= numin % size;
     bool inserted=false;

     //new element:
     info* zz = new info(numin,user);

     //double hashing 1: no collision
     if (hashtv[x].phone==0 && inserted==false){

         hashtv[x]=*zz;
         hashtv[x].prev=nullptr;
         hashtv[x].next=nullptr;
        cleanptr(zz);
     
        inserted==true;
        inserttrack++;
 
        }    

     //chaining: collusion occurs, create linked list.
      else{

            //case : start creating chain
                    if (hashtv[x].phone!=0 && inserted==false){

                    //assigning a starting pointer in the hash table
    
                    info* hashtvp=&hashtv[x];
            

                    bool repeated= false;

                        if(repeated==false) {
                        //calling insert handlind function for chaining
                        insert(hashtvp,zz);
                        cleanptr(zz);
                        cleanptr(hashtvp);
                        inserted==true;
                        }              
                
                }

        }  
}

//assign pointer to null and delete.
void hasht::cleanptr(info* current) {
    current=nullptr;
    delete current;

}//end of clean pointer

   //searching from the end of the chain 
info* hasht::findend(info* xx){

       info* x = xx;
      while(x!=nullptr && x->next!=nullptr) {
         x=x->next;
       }
      return x;
       }

     //now x is the end of the chain, start search to the previous
info* hasht::findfront(info* xx) {

         info* x= xx;

           while(x!=nullptr && x->next!=nullptr) {
           x=x->prev;
         }
          return x;
       }


void hasht::deletechain(long kk) {

    info* i;
    info* j;
    info* k;

 bool found=false;
 long a= kk%size;

  //case1 on hash array address
  if(hashtv[a].phone==kk){

           j=&hashtv[a];
           //j is the only element in the current chain
           if(j->prev==nullptr && j->next==nullptr && found==false){
               j->phone=0;
               j->user="";
               found=true;
           }

           if( j->next!=nullptr && found==false){
               //using next to replace
               k=j->next;
               j->next= k->next;
               j->phone=k->phone;
               j->user=k->user;

               if(j->next!=nullptr){

                   i=j->next;
                   i->prev=k->prev;            
               }

               //delete the element that is copied
               k=nullptr;
               delete k;
                found=true;

           }      

       }

    
    //end of case 1

    //case 2, need to search in the chain
    // searching from the end of the chain 
    if(hashtv[a].phone!=kk){

        j= &hashtv[a];
        j=findend(j);
        
        //if the end is target to delete:
        if(j->phone==kk) {
            i=j->prev;
            i->next=nullptr;
            j=nullptr;
            delete j;
            found==true;
      
        }

        while(found==false && j!=nullptr) {
         if(j->phone==kk) {

             //deletion 
             k=j->next;
             i=j->prev;
             if(k!=nullptr){
                 i->next=k;
             }

             k->prev=i;
             j=nullptr;
             delete j;

             found=true;     
          }
         else{
            j=j->prev;
            }

        }   

    }// end of if(hashtv[a].phone!=kk)


}//end of delete



//search for a phone number
void hasht::searchchain(long k) {

 bool found=false;
 long a= k%size;
  if(hashtv[a].phone==k){
    cout<<"found "<<hashtv[a].user<<" in "<< a<<endl;
    found= true;
    }

  if(found==false) {

    info* x= &hashtv[a];

    //searching from the end of the chain 
    while(x!=nullptr && x->next!=nullptr) {
         x=x->next;
     }

     //now x is the end of the chain, start search to the previous
     while(found==false &&x!=nullptr) {

         if(x->phone==k) {
             found=true;
             cout<<"found "<<x->user<<" in "<< a<<endl;
          }

         x=x->prev;

        }

     }

     if(found==false) {

         cout<<"not found" <<endl;
     }
}

    



//inserting in a non-empty chain, use this when collision occurs and chain has to take place.
void hasht::insert(info* hashtvin, info* zz){

  //always insert at the very last chain, then do linear sort

     info* x = hashtvin;
     info* z= zz;

     //looping to get the very last element

     while(x!=nullptr && x->next!=nullptr) {
         x=x->next;
     }
     //now the new elememt is the last element in the chain
     x->next=z;
     z->prev=x;

 }

 void hasht::sortchain(info* zz){

     //only use sort before printing

     info* z=zz;
     info* x;
     x=z->prev;
     info* y;
     

     //linear sorting in a linked list. the largest phone value is in the end of the chain

     while (z->phone< x->phone) {

         //putting z before x:
         x->next=z->next;
         z->next=x;
         if(x->prev!= nullptr) {
             y=x->prev;
             y->next=z;
         }
         z->prev=x->prev;
         x->prev=z;
     }


 }

//printing the entire chain of an entry in the hash table, i is the index of the hash table; for chaining only
void hasht::print(long i) {

    //set up poiners to loop through a chain. 

     info* currentp= &hashtv[i];

     //sorting the entire chain with smallest numbers first and largest the last
     sortchain(currentp);
     
     //the smallest number is to be place in the previous element, printing from the smallest to the largest
      //if the hash has something in it:
     if(hashtv[i].phone!=0) {
            //starting from the smallest element.

            while (currentp->prev!=nullptr) {
                currentp=currentp->prev;
             } 
                //first element print:

                 cout<< currentp->phone <<" ";
                // starting the next element and print successive ones. a "do while" 
                currentp= currentp->next;
                //continue to print elements after the current pointer
                while (currentp!= nullptr && hashtv[i].phone!=0) {
            
                    cout<< currentp->phone <<" "; 
                
                    //go to the next chain
                    currentp= currentp->next;
        }         
     }
        cleanptr(currentp);
}





