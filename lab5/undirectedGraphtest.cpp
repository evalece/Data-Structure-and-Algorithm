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

#include "heap.h"
#include "undirectedGraph.h"
#include "ugDriver.h"


//forward declear
class ugDriver;
class heap;
class undirectedGraph;

using namespace std; 

int main(){

//parsing user inputs and run only one line at the time:
  string line; //reading line by line from input file.

 /////*t is edit pointer

  //tt is a instance of driver 
   ugDriver* driverptr= new ugDriver(0,0);
 


  
  //reading array size from input 
  while ( getline (cin,line) ){ // from <string> - http://www.cplusplus.com/reference/string/string/getline/

  //initializing mst
    if (line.find("i ")==0){

      string city=(line.substr(2,line.length()));

         
       cout<< "i;"<< city<<endl;
        bool ins= driverptr->insert(city);
        if(ins==1){
        cout<<"success"<<endl;
        }
        else{
            cout<<"failure"<<endl;
        }
       
    
      }//end of n command.
          
    

  // set distince (setd)
    if (line.find("setd ")==0){

        //cout<< "i command " << endl;
        string nnn= line.substr(5,line.find(";")-5);
        line= line.substr(line.find(";")+1,line.length());
        string xxx= line.substr(0,line.find(";"));
        line= line.substr(line.find(";")+1,line.length());
        double yyy= stod(line.substr(0,line.length()));


          /*
           //cout<<"success"<< endl;
           cout<< "setd; nnn:"<<nnn<<endl;
           cout<< "setd; xxx:"<<xxx<<endl;
           cout<< "setd; yyy:"<<yyy<<endl; 
           */

      //// cout<< "setd"<<endl;

        bool ins=  driverptr->setd(nnn,xxx,yyy);
        if(ins==1){
        cout<<"success"<<endl;
        }
        else{
            cout<<"failure"<<endl;
        }


    }//end of setd
    



  //s command Searches for a city with the specified name.
    if (line.find("s ")==0){
      //cout<< "clear command" <<endl;


       string xxx= line.substr(2,line.find(";"));

       cout<< "s; xxx="<< xxx <<endl;

        bool ins=  driverptr->look_up_check(xxx);
        if(ins==1){
        cout<<"success"<<endl;
        }
        else{
            cout<<"failure"<<endl;
        }
  
    }

  //degree of one city (nodes)
    if (line.find("degree ")==0){


        string xxx= line.substr(7,line.find(";"));
        // cout<< "degree; xxx="<< xxx <<endl;

        int ins=  driverptr->degree(xxx);

        if(ins>0){

            /////cout<<"something" <<endl;
        cout<<ins<<endl;
        }
        else{
            cout<<"failure"<<endl;
        }
        

  
    }  


    //graph_nodes 
    if (line.find("graph_nodes ")==0){

        //cout number of city (node)
        //string xxx= line.substr(7,line.find(";"));

       //cout<< "graph_nodes;" <<endl;
       cout<<"number of nodes " <<driverptr->nodes<<endl;

  
    }  

    //graph_edges
    if (line.find("graph_edges ")==0){

        //cout number of road (edges)

       //cout<< "graph_edges;" <<endl;
         cout<<"number of edges "<<driverptr->global_edge_count<<endl;
  
    }  


    //d - Prints the distance between two cities (name1 and name2) along the edge directly connecting them.
     if (line.find("d ")==0){

         //cout<< "i command " << endl;
        string nnn= line.substr(2,line.find(";")-2);
        line= line.substr(line.find(";")+1,line.length());
        string xxx= line.substr(0,line.find(";"));
       
        //cout<<"success"<< endl;
        /*
        cout<< "d; nnn:"<<nnn<<endl;
        cout<< "d; xxx:"<<xxx<<endl;
        */
        int ins= driverptr->d(nnn,xxx);
        if(ins!=INFINITY){
        cout<<"direct distance "<< nnn <<" to " <<xxx <<" " <<ins<<endl;
        }
        else{
            cout<<"failure"<<endl;
        }
        


     }//end d 



    //shortest_d - Finds the shortest distance between two cities (name1 and name2).
    if (line.find("shortest_d ")==0){

        string nnn= line.substr(11,line.find(";")-11);
        line= line.substr(line.find(";")+1,line.length());
        string xxx= line.substr(0,line.length());
       
        //cout<<"success"<< endl;
        /*
        cout<< "shortest_d; nnn:"<<nnn<<endl;
        cout<< "shortest_d; xxx:"<<xxx<<endl; 
        */



        bool a=driverptr->look_up_check(nnn);
        bool b=driverptr->look_up_check(xxx);
        //both city exist and are of different names
          if(a&&b&&nnn!=xxx){
        int index1=driverptr->look_up(nnn);
        int index2=driverptr->look_up(xxx);

        driverptr->ini_visit();

        double ss= driverptr->shortest_d(index1,index2);

        if(ss!=INFINITY){
          cout<<"shortest distance " << nnn<< " to " << xxx <<" "<< ss<<endl;
        }
        if(ss==INFINITY){
          cout<< "failure"<<endl;
        }

      }

    }// end of shortest_d

    //print_path - Prints the path between two cities 
    //(name1 and name2) such that the sum of the distances of its constituent edges (roads) is minimized (shortest path).
    if (line.find("print_path ")==0){

        string nnn= line.substr(11,line.find(";")-2);
        line= line.substr(line.find(";")+1,line.length());
        string xxx= line.substr(0,line.length());
       
        //cout<<"success"<< endl;
        /*
        cout<< "print_path; nnn:"<<nnn<<endl;
        cout<< "print_path; xxx:"<<xxx<<endl; 
        */

         bool a=driverptr->look_up_check(nnn);
        bool b=driverptr->look_up_check(xxx);
        //both city exist and are of different names
          if(a&&b&&nnn!=xxx){
        int index1=driverptr->look_up(nnn);
        int index2=driverptr->look_up(xxx);
        driverptr->print_path(index1,index2);


         }

         else{
           cout<<"failure"<<endl;
         }
        


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
 


   
