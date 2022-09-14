/**
    ECE250
    qttest.cpp
    Purpose: provide a .exe function for user input and function calls to nodes and trees.
    Provides access to tree and node functions 

    Author Eva Liu ID:20724405 UWID:lj2liu
    Version 2.1  - 12/03/2020
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
         
            tt.print(tt.root);

                 //next line will start the new line
                 cout<<endl;
     
          }



    if (line.find("i")==0){

        string nnn= line.substr(line.find("i ")+2,line.find(";")-2);
        line= line.substr(line.find(";")+1,line.length());

     
        
        double xxx= stod(line.substr(0,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        double yyy= stod(line.substr(0,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        int ppp= stoi(line.substr(0,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        int rrr= stoi(line.substr(0,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        int sss= stoi(line.substr(0,line.find(";")));
       
        tt.forinsert(nnn,xxx,yyy,ppp,rrr,sss);
        tt.insert(tt.root,tt.toInsert);

      }
    


    if (line.find("s ")==0){



      //search will fisrt create a dummy node for passing dummy pointer. This is becauase we want to call search recursively by passing pointers



       double xxxs= stod(line.substr(2,line.find(";")-2));
       double yyys= stod(line.substr(line.find(";")+1,line.length()));
      


        node* dummy= new node("dummy",xxxs,yyys,0,0,0);
        //call root and dummy:
        tt.search(tt.root,dummy);
  

        dummy=nullptr;
        delete dummy;

       //tt.cleanptr(dummy);
       
    
    }
    if (line.find("size")==0){
        cout<< "tree size " << tt.size<<endl;  
    }
    if( (line.substr(0,line.find(" ")))=="q_max") {   



         //critria in xxxq (x-coord.), yyyq(y-coord.), pppq(directon), rrrq (attribute).
       string xxxa= (line.substr(0,line.find(";")));
       double xxxq= stod(xxxa.substr(6,line.find(";")));

        line= line.substr(line.find(";")+1,line.length());
        double yyyq= stod(line.substr(0,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        string pppq= (line.substr(0,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        string rrrq= (line.substr(0,line.find(";")));

 

          //this dummy will be passed to searchnode for matching city first.
          node* dummy = new node("dummy",xxxq,yyyq,0,0,0);

          //dummy1 is the city that has xxxq and yyyq coordinates 
           node* dummy1= tt.searchnode(tt.root,dummy);


          if(dummy1==nullptr) {


           cout<< "failure" <<endl;
          }

         if(dummy1!=nullptr) {
                if(pppq=="NE") {

                  tt.q_max(dummy1->ne,rrrq);

                }

                if(pppq=="NW") {

                  tt.q_max(dummy1->nw,rrrq);             
                }

                if(pppq=="SW") {
                    tt.q_max(dummy1->sw,rrrq);            
                }

                if(pppq=="SE") {

                    tt.q_max(dummy1->se,rrrq);            
                }
                

         }//end of dummy !=nullptr;
    


          if(tt.max!=0) {
         cout<<"max "<<tt.max<<endl;

         }

         if(tt.max==0 && dummy1!=nullptr) {
           cout<<"failure" <<endl;
         }

         //reset tt.max
         tt.max=0;
          dummy=nullptr;
          dummy1=nullptr;
         delete dummy;
         delete dummy1;

        }//end of q_max

    if( (line.substr(0,line.find(" ")))=="q_min") {   
        //critria in xxxq (x-coord.), yyyq(y-coord.), pppq(directon), rrrq (attribute).
       string xxxa= (line.substr(0,line.find(";")));
       double xxxq= stod(xxxa.substr(6,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        double yyyq= stod(line.substr(0,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        string pppq= (line.substr(0,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        string rrrq= (line.substr(0,line.find(";")));

          //this dummy will be passed to searchnode for matching city first.
          node* dummy = new node("dummy",xxxq,yyyq,0,0,0);

          //dummy1 is the city that has xxxq and yyyq coordinates 
           node* dummy1= tt.searchnode(tt.root,dummy);

          if(dummy1==nullptr) {

           cout<< "failure" <<endl;
          }

         if(dummy1!=nullptr) {
           //use dummy1 's criteria as min value for later comparison, criteria is in rrrq
           ////p and all directions
           if(rrrq=="p" && pppq=="NE") {
             if(dummy1->ne!=nullptr) {
              tt.min=dummy1->ne->p;
              }
            if(dummy1->ne==nullptr) {
              tt.min=0;
            }
           }

            if(rrrq=="p" && pppq=="NW") {
             if(dummy1->nw!=nullptr) {
              tt.min=dummy1->nw->p;
              }
            if(dummy1->nw==nullptr) {
              tt.min=0;
            }
            }

            if(rrrq=="p" && pppq=="SW") {
             if(dummy1->sw!=nullptr) {
              tt.min=dummy1->sw->p;
              }
            if(dummy1->sw==nullptr) {
              tt.min=0;
            }
            }

            if(rrrq=="p" && pppq=="SE") {
             if(dummy1->se!=nullptr) {
              tt.min=dummy1->se->p;
              }
            if(dummy1->se==nullptr) {
              tt.min=0;
            }

           }

          ///r and all directions
           if(rrrq=="r" && pppq=="NE") {
             if(dummy1->ne!=nullptr) {
              tt.min=dummy1->ne->r;
              }
            if(dummy1->ne==nullptr) {
              tt.min=0;
            }
           }

            if(rrrq=="r" && pppq=="NW") {
             if(dummy1->nw!=nullptr) {
              tt.min=dummy1->nw->r;
              }
            if(dummy1->nw==nullptr) {
              tt.min=0;
            }
            }

            if(rrrq=="r" && pppq=="SW") {
             if(dummy1->sw!=nullptr) {
              tt.min=dummy1->sw->r;
              }
            if(dummy1->sw==nullptr) {
              tt.min=0;
            }
            }

            if(rrrq=="r" && pppq=="SE") {
             if(dummy1->se!=nullptr) {
              tt.min=dummy1->se->r;
              }
            if(dummy1->se==nullptr) {
              tt.min=0;
            }
            }

            ///////s and all directions
           if(rrrq=="s" && pppq=="NE") {
             if(dummy1->ne!=nullptr) {
              tt.min=dummy1->ne->s;
              }
            if(dummy1->ne==nullptr) {
              tt.min=0;
            }
           }

            if(rrrq=="s" && pppq=="NW") {
             if(dummy1->nw!=nullptr) {
              tt.min=dummy1->nw->s;
              }
            if(dummy1->nw==nullptr) {
              tt.min=0;
            }
            }

            if(rrrq=="s" && pppq=="SW") {
             if(dummy1->sw!=nullptr) {
              tt.min=dummy1->sw->s;
              }
            if(dummy1->sw==nullptr) {
              tt.min=0;
            }
            }

            if(rrrq=="s" && pppq=="SE") {
             if(dummy1->se!=nullptr) {
              tt.min=dummy1->se->s;
              }
            if(dummy1->se==nullptr) {
              tt.min=0;
            }
            }
                //start calling recursive function using rrrq as criteria

                if(pppq=="NE") {

       
                  tt.q_min(dummy1->ne,rrrq);

                }

                if(pppq=="NW") {

             
                  tt.q_min(dummy1->nw,rrrq);             
                }

                if(pppq=="SW") {
                    tt.q_min(dummy1->sw,rrrq);            
                }

                if(pppq=="SE") {

                    tt.q_min(dummy1->se,rrrq);            
                }
                

         }//end of dummy !=nullptr;


          if(tt.min!=0) {
         cout<<"min "<<tt.min<<endl;

         }

         if(tt.min==0 && dummy1!=nullptr) {
           cout<<"failure" <<endl;
         }

         //reset tt.max
         tt.min=0;


          dummy =nullptr;
          dummy1=nullptr;
          delete dummy;
          delete dummy1;

      }//end of q_ min



   
    if((line.substr(0,line.find(" ")))=="q_total") {   


        //critria in xxxq (x-coord.), yyyq(y-coord.), pppq(directon), rrrq (attribute).
       string xxxa= (line.substr(0,line.find(";")));
       double xxxq= stod(xxxa.substr(8,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        double yyyq= stod(line.substr(0,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        string pppq= (line.substr(0,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        string rrrq= (line.substr(0,line.find(";")));
    

          //this dummy will be passed to searchnode for matching city first.
          node* dummy = new node("dummy",xxxq,yyyq,0,0,0);

          //dummy1 is the city that has xxxq and yyyq coordinates 
           node* dummy1= tt.searchnode(tt.root,dummy);

          if(dummy1==nullptr) {

           cout<< "failure" <<endl;
          }

         if(dummy1!=nullptr) {
                if(pppq=="NE") {

                  tt.q_total(dummy1->ne,rrrq);

                }

                if(pppq=="NW") {

                  tt.q_total(dummy1->nw,rrrq);             
                }

                if(pppq=="SW") {
                    tt.q_total(dummy1->sw,rrrq);            
                }

                if(pppq=="SE") {

                    tt.q_total(dummy1->se,rrrq);            
                }
                

         }//end of dummy !=nullptr;


          if(tt.total!=0) {
         cout<<"total "<<tt.total<<endl;

         }

         if(tt.total==0 && dummy1!=nullptr) {
           cout<<"failure" <<endl;
         }

         //reset tt.total
         tt.total=0;

         
         dummy1=nullptr;
         dummy=nullptr;
         delete dummy;
         delete dummy1;
         

      }//end of totoal

    if((line.substr(0,line.find(" ")))=="clear") {

      //resursive function
      tt.clear(tt.root);
      //there is no failure for clear
      tt.root=nullptr;

      //the recursive call doesn't clean root so call clean root here once more:
      delete tt.root;
    
      cout<<"success" <<endl;
    }
    
    }//end of while
   
   return 0;

}//end of main
 


   
