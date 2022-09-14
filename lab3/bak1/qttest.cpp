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
#include "tree.h"

using namespace std; 

int main(){

//parsing user inputs and run only one line at the time:

  string line; //reading line by line from input file.
  string command; //the parsed command. 

  int inx; 
  tree tt; 
 
  
    //reading array size from input 
    while ( getline (cin,line) ){ // from <string> - http://www.cplusplus.com/reference/string/string/getline/
          
    
          
     if (line.find("print")==0) {
               cout<< "print" <<endl;
                 tt.print(tt.root);
     
          }



      if (line.find("i")==0){

        string nnn= line.substr(line.find("i ")+2,line.find(";")-2);
        line= line.substr(line.find(";")+1,line.length());

        cout<< "nnn=" <<nnn<<endl;
        
        float xxx= stof(line.substr(0,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        float yyy= stof(line.substr(0,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        int ppp= stoi(line.substr(0,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        float rrr= stof(line.substr(0,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        float sss= stof(line.substr(0,line.find(";")));
       
        tt.forinsert(nnn,xxx,yyy,ppp,rrr,sss);
        tt.insert(tt.root,tt.toInsert);

      }


    }
      
      
   return 0;
}


   
