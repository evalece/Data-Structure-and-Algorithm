/**
    ECE250
    undirectedGraphtest.cpp
    Purpose: provide a .exe function for user input and function calls/ drives to nodes and ug.
    Provides service to pass command and catch exception and error handling.
    Re-allocating mst instances after clear.
    

    Author Eva Liu ID:20724405 UWID:lj2liu
    Version 2.1  - 12/03/2020
*/
#include <iostream>
#include <fstream>
#include <string>

#include "ugDriver.h"
#include "heap.h"


using namespace std; 

int main(){

//parsing user inputs and run only one line at the time:
  string line; //reading line by line from input file.


  ugDriver* t=new ugDriver; 
 
  
  //reading array size from input 
  while ( getline (cin,line) ){ // from <string> - http://www.cplusplus.com/reference/string/string/getline/

  //initializing mst
    if (line.find("i ")==0){

      string city=(line.substr(2,line.length()));

         
       cout<< "i;"<< city<<endl;


    
      }//end of n command.
          
    

  // set distince (setd)
    if (line.find("setd ")==0){

        //cout<< "i command " << endl;
        string nnn= line.substr(5,line.find(";")-5);
        line= line.substr(line.find(";")+1,line.length());
        string xxx= line.substr(0,line.find(";"));
        line= line.substr(line.find(";")+1,line.length());
        string yyy= line.substr(0,line.length());


          
           //cout<<"success"<< endl;
           cout<< "setd; nnn:"<<nnn<<endl;
           cout<< "setd; xxx:"<<xxx<<endl;
           cout<< "setd; yyy:"<<yyy<<endl; 

       


    }//end of setd
    





  //s command Searches for a city with the specified name.
    if (line.find("s ")==0){
      //cout<< "clear command" <<endl;


       string xxx= line.substr(2,line.find(";"));

       cout<< "s; xxx="<< xxx <<endl;

      //cout<<"success"<<endl;
  
    }

  //degree of one city (nodes)
    if (line.find("degree ")==0){


        string xxx= line.substr(7,line.find(";"));
       cout<< "degree; xxx="<< xxx <<endl;

  
    }  


    //graph_nodes 
    if (line.find("graph_nodes ")==0){

        //cout number of city (node)
        //string xxx= line.substr(7,line.find(";"));

       cout<< "graph_nodes;" <<endl;

  
    }  

    //graph_edges
    if (line.find("graph_edges ")==0){

        //cout number of road (edges)

       cout<< "graph_edges;" <<endl;
  
    }  


    //d - Prints the distance between two cities (name1 and name2) along the edge directly connecting them.
     if (line.find("d ")==0){

         //cout<< "i command " << endl;
        string nnn= line.substr(2,line.find(";")-2);
        line= line.substr(line.find(";")+1,line.length());
        string xxx= line.substr(0,line.find(";"));
       
        //cout<<"success"<< endl;
        cout<< "setd; nnn:"<<nnn<<endl;
        cout<< "setd; xxx:"<<xxx<<endl;

     }//end d 



    //shortest_d - Finds the shortest distance between two cities (name1 and name2).
    if (line.find("shortest_d ")==0){

        string nnn= line.substr(11,line.find(";")-11);
        line= line.substr(line.find(";")+1,line.length());
        string xxx= line.substr(0,line.length());
       
        //cout<<"success"<< endl;
        cout<< "shortest_d; nnn:"<<nnn<<endl;
        cout<< "shortest_d; xxx:"<<xxx<<endl; 

    }// end of shortest_d

    //print_path - Prints the path between two cities 
    //(name1 and name2) such that the sum of the distances of its constituent edges (roads) is minimized (shortest path).
    if (line.find("print_path ")==0){

        string nnn= line.substr(11,line.find(";")-2);
        line= line.substr(line.find(";")+1,line.length());
        string xxx= line.substr(0,line.length());
       
        //cout<<"success"<< endl;
        cout<< "print_path; nnn:"<<nnn<<endl;
        cout<< "print_path; xxx:"<<xxx<<endl; 

    }// end of shortest_d  

    //clear

    if (line.find("clear ")==0){

        cout<< "clear"<<endl;


    }// end of shortest_d  


  }//end of while

  //clear pointer
 // tt=nullptr;
 /// delete tt;
   
   return 0;

}//end of main
 


   