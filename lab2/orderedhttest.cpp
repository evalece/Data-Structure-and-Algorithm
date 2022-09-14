//using chinaing
#include <iostream>
#include <fstream>
#include <string>
#include "hasht.h"

using namespace std; 

int main(){

    
//parsing user inputs and run only one line at the time:

  string line; //reading line by line from input file.
  string command; //the parsed command. 
 
  string caller; //user input
  long  k; //phone number


//instance of the class3
hasht a;

 //reading array size from input 
    while ( getline (cin,line) ){ // from <string> - http://www.cplusplus.com/reference/string/string/getline/
          
          //define hash table size
     if (line.find("n ")==0) {    

         int size= stol(line.substr(2,line.length()));

         a.resizeinfo(size);

         cout<< "0: "<<size<< endl;



          }

            //insert k, caller (number and user)
          if (line.find("i ")==0) {

                
            k= stol(line.substr(2,10));
            cout<< "inserting k="<< k << endl;
            caller= line.substr(line.find(";")+1,line.length());

            //cout<< "caller="<< caller << endl;

            a.dh(k,caller);
  
      
            }

            //search for k
          if (line.find("s ")==0) {

           k= stol(line.substr(2,10));
           cout<< "search for " << k << endl;
           a.search( k);
      
            }

            //search for k and delete it
          if (line.find("d ")==0) {
          k= stol(line.substr(2,10));

          cout<< "deleting k=" << k <<endl;
          a.deleteinfo(k);





           
          }


            //print position i's chain (linked list)
         if (line.find("p ")==0) {

 
          k= stol(line.substr(2,10));

          cout<< "call p " << endl;
          //a.print(5);

            for(int i=0; i<10;i++){
                      // cout<<"(5197225184/10)%10:"<<(5197225184/10)%10<<endl;
             cout<< "i:" << i<< endl;
              a.print(i);
              //to next line
              cout<< endl;
       

            }
    
          

        }

    }
      
   return 0;



}