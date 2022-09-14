/**
    ECE250
    dequedriver.cpp
    Purpose: Parsing user inputs and catch unexpected inputs. 
    Provides services to call linkList functions based on user inputs.

    Author Eva Liu
    Version 1.0  - 27/01/2020
*/

#include <iostream>
#include <fstream>
#include <string>

#include "node.h"
#include "linkList.h"

using namespace std; 

int main(){

//parsing user inputs and run only one line at the time:

  string line; //reading line by line from input file.
  string command; //the parsed command. 

  int inx; 
  linkList mainll; 
 
  
    //reading array size from input 
    while ( getline (cin,line) ){ // from <string> - http://www.cplusplus.com/reference/string/string/getline/
          
    if (line.find("enqueue_front")==0) {    

         //cout<< "enqueue_front." <<endl;

         inx= stoi(line.substr(13, line.length())); 
         mainll.enqueue_front(inx);
           
          }

    if (line.find("enqueue_back")==0) {
              // cout<< "enqueue_back." <<endl;
               inx= stoi(line.substr(13, line.length())); 
               mainll.enqueue_back(inx);

           
            }

    if (line.find("dequeue_front")==0) {
              // cout<< "dequeue_front" <<endl;
               mainll.dequeue_front();
 
             
            
            }

    if (line.find("dequeue_back")==0) {
              // cout<< "dequeue_back" <<endl;
               mainll.dequeue_back();
           
             }   


    if (line.find("clear")==0) {
              //  cout<< "clear" <<endl;
                mainll.clear();

       
          }

    if (line.find("front")==0) {
               // cout<< "front" <<endl;
                inx= stoi(line.substr(6, line.length())); 
                //cout<<"inx in front :"<<inx<<endl;
                mainll.front(inx);
       
          }

    if (line.find("back")==0) {
               // cout<< "back" <<endl;

                inx= stoi(line.substr(5, line.length()));
                //cout<<"inx in back :"<<inx<<endl; 
                mainll.back(inx);    
          }

    if (line.find("empty")==0) {
               // cout<< "empty" <<endl;
                mainll.empty();
       
          }

    if (line.find("size")==0) {
               // cout<< "size" <<endl;
                mainll.size();

       
          }
          
     if (line.find("print")==0) {
              //  cout<< "print" <<endl;
                 mainll.print();

       
          }


        }
      
   return 0;
}


   
