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
         
            tt.print(tt.root);

                 //next line will start the new line
                 cout<<endl;
     
          }



    if (line.find("i")==0){

        string nnn= line.substr(line.find("i ")+2,line.find(";")-2);
        line= line.substr(line.find(";")+1,line.length());

     
        
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
    


    if (line.find("s ")==0){

      //cout<<"search" <<endl;


      //search will fisrt create a dummy node for passing dummy pointer. This is becauase we want to call search recursively by passing pointers



       float xxxs= stof(line.substr(2,line.find(";")-2));
       float yyys= stof(line.substr(line.find(";")+1,line.length()));
      


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


      //cout<< "1"<<endl;


      //cout<<" line:"<< line <<endl;
        //critria in xxxq, yyyq, pppq, rrrq.
       string xxxa= (line.substr(0,line.find(";")));
       float xxxq= stof(xxxa.substr(6,line.find(";")));

        //xstring xxxq= (line.substr(7,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        float yyyq= stof(line.substr(0,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        string pppq= (line.substr(0,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        string rrrq= (line.substr(0,line.find(";")));

          /*
             cout<<"xxxq=" <<xxxq <<endl;
             cout<<"yyyq=" <<yyyq <<endl;
              cout<<"pppq=" <<pppq <<endl;
               cout<<"rrrq=" <<rrrq <<endl;
               */

                          //cout<< "1.1"<<endl;

          //this dummy will be passed to searchnode for matching city first.
          node* dummy = new node("dummy",xxxq,yyyq,0,0,0);

          //dummy1 is the city that has xxxq and yyyq coordinates 
           node* dummy1= tt.searchnode(tt.root,dummy);

          // cout<< "dummy1=" << dummy1->name<<endl;

           // cout<< "2"<<endl;

          if(dummy1==nullptr) {

        //      // cout<< "3"<<endl;

           cout<< "failure" <<endl;
          }

         if(dummy1!=nullptr) {
                if(pppq=="NE") {

                  //cout<<"pppq==ne" <<endl;
                    // cout<< "4"<<endl;
                  tt.q_max(dummy1->ne,rrrq);

                }

                if(pppq=="NW") {

                 //    cout<<"pppq==nw" <<endl;
                  tt.q_max(dummy1->nw,rrrq);             
                }

                if(pppq=="SW") {
                 //    cout<<"pppq==sw" <<endl;
                    tt.q_max(dummy1->sw,rrrq);            
                }

                if(pppq=="SE") {

                  //   cout<<"pppq==se" <<endl;
                    tt.q_max(dummy1->se,rrrq);            
                }
                

         }//end of dummy !=nullptr;
            //cout<< "5"<<endl;


          if(tt.max!=0) {
         cout<<"max "<<tt.max<<endl;

         }

         if(tt.max==0) {
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


      //cout<< "1minnnnn"<<endl;


      //cout<<" line:"<< line <<endl;
        //critria in xxxq, yyyq, pppq, rrrq.
       string xxxa= (line.substr(0,line.find(";")));
       float xxxq= stof(xxxa.substr(6,line.find(";")));

        //xstring xxxq= (line.substr(7,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        float yyyq= stof(line.substr(0,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        string pppq= (line.substr(0,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        string rrrq= (line.substr(0,line.find(";")));

          /*
             cout<<"xxxq=" <<xxxq <<endl;
             cout<<"yyyq=" <<yyyq <<endl;
              cout<<"pppq=" <<pppq <<endl;
               cout<<"rrrq=" <<rrrq <<endl;
               

                          //cout<< "1.1"<<endl;

                        */

          //this dummy will be passed to searchnode for matching city first.
          node* dummy = new node("dummy",xxxq,yyyq,0,0,0);

          //dummy1 is the city that has xxxq and yyyq coordinates 
           node* dummy1= tt.searchnode(tt.root,dummy);



          // cout<< "dummy1=" << dummy1->name<<endl;



           // cout<< "2"<<endl;

          if(dummy1==nullptr) {

        //      // cout<< "3"<<endl;

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

                  //cout<<"pppq==ne" <<endl;
                    // cout<< "4"<<endl;
                  tt.q_min(dummy1->ne,rrrq);

                }

                if(pppq=="NW") {

                 //    cout<<"pppq==nw" <<endl;
                  tt.q_min(dummy1->nw,rrrq);             
                }

                if(pppq=="SW") {
                 //    cout<<"pppq==sw" <<endl;
                    tt.q_min(dummy1->sw,rrrq);            
                }

                if(pppq=="SE") {

                  //   cout<<"pppq==se" <<endl;
                    tt.q_min(dummy1->se,rrrq);            
                }
                

         }//end of dummy !=nullptr;
            //cout<< "5"<<endl;


          if(tt.min!=0) {
         cout<<"min "<<tt.min<<endl;

         }

         if(tt.min==0) {
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


      //cout<< "1"<<endl;


      //cout<<" line:"<< line <<endl;
        //critria in xxxq, yyyq, pppq, rrrq.
       string xxxa= (line.substr(0,line.find(";")));
       float xxxq= stof(xxxa.substr(8,line.find(";")));

       //cout<<"line--" << line <<endl;

        //xstring xxxq= (line.substr(7,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        float yyyq= stof(line.substr(0,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        string pppq= (line.substr(0,line.find(";")));
        line= line.substr(line.find(";")+1,line.length());
        string rrrq= (line.substr(0,line.find(";")));

          /*
             cout<<"xxxq=" <<xxxq <<endl;
             cout<<"yyyq=" <<yyyq <<endl;
              cout<<"pppq=" <<pppq <<endl;
               cout<<"rrrq=" <<rrrq <<endl;
               

                          //cout<< "1.1"<<endl;

                 */       

          //this dummy will be passed to searchnode for matching city first.
          node* dummy = new node("dummy",xxxq,yyyq,0,0,0);

          //dummy1 is the city that has xxxq and yyyq coordinates 
           node* dummy1= tt.searchnode(tt.root,dummy);

          // cout<< "dummy1=" << dummy1->name<<endl;

           // cout<< "2"<<endl;

          if(dummy1==nullptr) {

        //      // cout<< "3"<<endl;

           cout<< "failure" <<endl;
          }

         if(dummy1!=nullptr) {
                if(pppq=="NE") {

                  //cout<<"pppq==ne" <<endl;
                    // cout<< "4"<<endl;
                  tt.q_total(dummy1->ne,rrrq);

                }

                if(pppq=="NW") {

                 //    cout<<"pppq==nw" <<endl;
                  tt.q_total(dummy1->nw,rrrq);             
                }

                if(pppq=="SW") {
                 //    cout<<"pppq==sw" <<endl;
                    tt.q_total(dummy1->sw,rrrq);            
                }

                if(pppq=="SE") {

                  //   cout<<"pppq==se" <<endl;
                    tt.q_total(dummy1->se,rrrq);            
                }
                

         }//end of dummy !=nullptr;
            //cout<< "5"<<endl;


          if(tt.total!=0) {
         cout<<"total "<<tt.total<<endl;

         }

         if(tt.total==0) {
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
 


   
