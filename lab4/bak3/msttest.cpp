/**
    ECE250
    msttest.cpp
    Purpose: provide a .exe function for user input and function calls to nodes and mst.
    Provides service to pass command and catch exception and error handling.
    

    Author Eva Liu ID:20724405 UWID:lj2liu
    Version 2.1  - 12/03/2020
*/
#include <iostream>
#include <fstream>
#include <string>

#include "node.h"
#include "mst.h"
#include "illegal_argument.h"

using namespace std; 

int main(){

//parsing user inputs and run only one line at the time:
  string line; //reading line by line from input file.

  int inx; 
  mst* tt; 
 
  
  //reading array size from input 
  while ( getline (cin,line) ){ // from <string> - http://www.cplusplus.com/reference/string/string/getline/

  //initializing mst
    if (line.find("n ")==0){

      inx=stoi(line.substr(2,line.length()));

      //if no exception is caught
      cout<< "success"<<endl;


       mst tt1(inx);
       tt=&tt1;
    
    
      }
          
    

  // inserting 
    if (line.find("i ")==0){

        //cout<< "i command " << endl;
        int nnn= stoi(line.substr(2,line.find(";")-2));
        line= line.substr(line.find(";")+1,line.length());
        int xxx= stoi(line.substr(0,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        double yyy= stod(line.substr(0,line.length()));

//debug
/*
                cout<< "nnn= " << nnn <<endl;
                cout<< "xxx= " << xxx <<endl;
                cout<< "yyy= " << yyy <<endl;
                */


      // exception and error handling for out of range nodes or invalid weight:

       //if no excpetion was caught:

       try{
         if(nnn>tt->m || xxx>tt->m || yyy<0 ||nnn<0||xxx<0 ){
            throw illegal_argument();
         }
       

        else {
          
          cout<<"success"<< endl;
           //insert(parent, child, weight), let parent < child always.
            if(nnn<xxx){
            tt->insert(nnn,xxx,yyy);
            }

            if(nnn>xxx){
            tt->insert(xxx,nnn,yyy);
            }   
        }//end of else
      }//end of try
      catch(illegal_argument ill) {
        cout<<"failure"<<endl;
      }


    }//end of insert
    

  //delete nodes between vertcies u and v
    if (line.find("d ")==0){

      bool deleted=false;

        int xxx= stoi(line.substr(2,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        int yyy= stoi(line.substr(0,line.length()));


          //smaller value is parent. del(int arent, int child)

          try{

            if(yyy>tt->m || xxx>tt->m || yyy<0 || xxx<0){
              throw illegal_argument();
            }
            else{
                  if(xxx<yyy) {
                  deleted= tt->del( xxx, yyy);
                  }

                if(xxx>yyy) {
                  deleted= tt->del(yyy, xxx);          
                  }

                if(deleted==true){
                  cout<<"success"<<endl;
                }

                else{
                  cout<<"failure"<<endl;
                  //the failure will be catched by del function in mst
                }

            }// end of else
          }//end of try
          //illegal argument catches wrong input range values and return failure.
          catch(illegal_argument ill) {
           cout<<"failure"<<endl;
           }//end of catch
          

      }//end of delete

  //edge_count
    if (line.find("edge_count")==0){
      
      cout<< "edge count is " << tt->net.size()<<endl;
  
  
    }



  //clear
    if (line.find("clear")==0){
      //cout<< "clear command" <<endl;

      mst tt2;
      //for clear, simply change base address of the pointer with an new intitalized mst.
      tt= &tt2;


      cout<<"success"<<endl;
  
    }

  //mst
    if (line.find("mst")==0){

      tt->mintree();
      if(tt->not_con==false){
      cout<<"mst "<<tt->mst_weight<<endl;
      }

      else{
          cout<<"not connected"<<endl;
      }
  
  
    }  


    

  //degree  need to check valid input 
    if (line.find("degree ")==0){

      int a= stoi(line.substr(7, line.length()));

      //return result from net loop
      int defc=tt->degreev(a);

      try{
            //defc< 0 should never happen, but try catching it anyways.
          if(defc<0 || a>tt->m-1) {
            throw illegal_argument();
          }

          else {
            cout<< "degree of " <<a<< " is "<< defc <<endl;
          }
      
        }  //end of try
        catch(illegal_argument ill) {
        cout<<"failure"<<endl;
      }

        

    }//end of degree

  }//end of while

    
 

/*

  //debug
  tt->sortnet();
 
    tt->mintree();
        */



   
   return 0;

}//end of main
 


   
