/**
    ECE250
   mst.cpp

   the mst by the Greedy Method sorts each input nodes (one node contains the edge weight and the two vertices that forms it) from minimum weight cost
   to maximum weight cost. 

   A disjoing set (essentially an array, see #1 for more detail) helps tracking cycyles and disconections when mst total weight is called. 

    let n be the number of initilized vertex.
   #1 O(n):An array of int type. It stores parent and child info. Inititialize array with -1, minus means the node is a parent, 1 means the number of 
   vertices in the subtree. The child node index store the parent node number. A recursive call "find parent" is applied to find the ultimate parent 
   with the largest 

   #2: another array is to check the edge degree upon each input: an array size is n. Initialize all to 0. Upon each edge input, the parent and child vertex
   index is increamented by 1 per insertion. 
   

    Author Eva Liu ID:20724405 UWID:lj2liu
    Version 2.0  - 31/03/2020
*/

#include <iostream>
#include <vector>       // std::vector
#include <algorithm>    // std::sort
#include "node.h"
#include "mst.h"



using namespace std; 

/** 
 constructors and destructors
 */

mst::mst(){
    //do nothing
    }

mst::mst(int m_in){
    
    //initilize vertex # 
    m=m_in;

    //initialize on check array 
    for(int i=0; i<m; i++){

        check.push_back(-1);
        /*degug
        cout<< "check index " << i << ":"<< check[i]<<endl;
        */
       //cout<< "check[" <<i<<"]=" <<check[i] <<endl;
    }

    //index is node number
    vertex_count= new int[m];

    for(int i=0; i<m; i++){
    //initialize all as 0.
        vertex_count[i]=0;
    }
}// end of constructor


//copy constructor
mst::mst(mst const &cp){
    m=cp.m;
}

//destructor
mst::~mst() {

}//end of ~mst


/////////////////////////first part of functionality: insertion of nodes, delete and sort them when needed. 

void mst::insert(int parent_in, int child_in, double weight_in){

    bool replace=false;

    //insertion first check if an edge already exist O(m), m= net.size().

    int i= 0;

    while(replace== false &&  i< net.size()) {

        //a delete target is found 
        if(net[i].parent==parent_in && net[i].child==child_in) {
            replace=true;
            //update weight, don't push_back.
            net[i].weight=weight_in;    
        }
        i++;
    }

    //if this is a new edge
    if(replace==false){
        node* in= new node(parent_in,child_in,weight_in);
        //node insertion
        net.push_back (*in);

        cleanptr(in);
     }

        vertex_count[parent_in]=1;
        vertex_count[child_in]=1;

}//end of insertion

void mst::cleanptr(node* target){
    target=nullptr;
    delete target;
}//end of cleanptr


//sorting net array, from minimum to maximum
void mst::sortnet(){

sort(net.begin(), net.end(), [](node a, node b){

    return a.weight<b.weight;

    });

    //debug, checking sort result


    /*
    
    for(node netresult: net ){
        

        cout<<"weight="<< netresult.weight<<endl;
        cout<< "parent=" << netresult.parent<<endl;
        cout<< "child=" << netresult.child<<endl;

    }
    */
    
}//end of sort net


//delete an edge 
bool mst::del(int parent_in, int child_in){
    
    bool found =false;
    int i=0;

    while(found== false &&  i< net.size()) {

        //a delete target is found 
        if(net[i].parent==parent_in && net[i].child==child_in) {
            found=true;

            //delete and re-index net; use the last node to replace the deleted node, then pop back:
            net[i]=net[net.size()];
            net.pop_back();          
        }

        i++;

    }

    return found;

}


//checking the degree of the node v by looping through the net work, the output is the original network vertex degree
int mst::degreev(int v){

    //degree track
    int deg =0;

    //looping throgh to count vertex v as either child or parent

    //insertion first check if an edge already exist O(m), m= net.size().

    int i= 0;

    while(i< net.size()) {
        //a delete target is found 
        if(net[i].parent==v || net[i].child==v) {
            deg++;   
        }
        i++;
    }
    return deg;
}


////////////////////////////////////////second part of the functionality


//for check array, call this after sort
int mst::findparent( int a){

    

    int b=a;

    //recursion  
    /*
    cout<<"b=" <<b<<endl;
    cout<<"check[b]="<<check[b]<<endl;
    */

    //if the current node 

    if(check[b]>-1){
        return findparent(check[b]);
    }

    //If the value itseld is a parent
    if(check[b]<0){
       int  c=b;
       // cout<< "return b=" <<b<<endl;
        return c;
    }
    
    
    
   // cout<< "recursion returning b=" <<b <<endl;


    
}



void mst::mintree(){  

    //initialize mst total weight count
    mst_weight=0;

    not_con=false;

    //sorting first 
    sortnet();
     //check sort
    for (int i=0; i<m;i++) {
   // cout<< "net[" <<i<<"]" << net[i].weight<<endl;
    }


    //min is the accumulate edge weight. Accumulation m-1 times at most.
    int min=0;
    //determine ver-1 using vertex_count, aka accounting initialized vertex
   // int ver=0; 
    //counting initilzed vertices 

    //m1= the effective vetices (i.e. vertices that has been inserted) 


    //initialize check once more
    for(int i=0; i<m; i++){
    //initialize all as 0.
        check[i]=-1;
       // cout<< "check["<< i<< "]="<< check[i]<<endl;
    }


    

    int m1=0;
    for(int i=0; i<m; i++) {
        if(vertex_count[i]>0){
            m1++;
        }

        //cout<<"check[" << i<< "]=" <<check[i] <<endl;
    }

    //effective edge count (i.e. # of edge in the mst)
    int mm1=0;

   // cout<< "m1=" <<m1<<endl; 

        //checking  disconncections: if the ultimate parent's size is less than intilized vertices count, m1, then there exists a disconnection.
        //however, we can catch "Segmentation fault (core dumped)" as an indiction of disconnection, but core dumped is too low level to be catch, hence, try solving 
        //ultimate parent



    for(int i=0; i<net.size(); i++){
            

           // cout<< "i loop=" <<i<<endl;

            //get parent and child info from net
            int p = net[i].parent;
            int c = net[i].child;

            /*
             cout<<"check[p]=" <<check[p]<<endl;
             cout<<"check[c]=" <<check[c]<<endl;
             */

            //ultimate parent of child and parent: 
            int pp= findparent(p);
            // cout<<"U parent of"<<p<<"=" <<pp<<endl;
            int pc= findparent(c);
            // cout<<"U parent of"<<c<<"=" <<pc<<endl;




            //add the sum fist, then check for cycles
            //different ultimate parent, perform union and edge count guareentee no cycle 
            
            if(pp!=pc ){

               //cout<<"In pp!= pc :net[i].weight=" <<net[i].weight<<endl;
               mst_weight=mst_weight+ net[i].weight;
               //mm1 keeps track of the effective edge in the mst (# of edge whose weights are taken into account)
               mm1++;

               bool done= false;
        

                //case 1: ultimate parent of the same degree
                if(check[pp]==check[pc]){

                    //ultimate parent adds one vertice
                    check[pp]=check[pp]+check[pc];
                    //child take ultimate parent as parent.
                    check[pc]=pp;

                    done=true;
                }//end of case 1
                
 

                //case 2: ultimate parent of different degree
                if(check[pp]!=check[pc] && done==false){
                  //select the larger subtree as new ultimate parent              
                    if(check[pp]<check[pc]){
                        //parent's ultimate parent is a larger subtree, parent follows ultimate parent, and child follows parent
                        
                        check[pp]=check[pp]+check[pc];
                        //child take ultimate parent as parent.
                        check[pc]=pp;  

                        done=true;     
                                        
                    }

                    if(done==false){
                        // otherwise, pc more negative, pc is the ultimate parent 
                        check[pc]=check[pp]+check[pc];
                        //child take ultimate parent as parent.
                        check[pp]=pc; 

                    }

                }//end of case 2

                

      

            }// end of for "non cycle detected"
            

            if(pp==pc) {

                //cycle is detected
            }
      
        }// end of for loop

        //not connected if some nodes are not initialized (m1!= m)
        //or effecive edge is not m-1

        /*

        for(int i=0; i<m; i++) {

        cout<<"check[" << i<< "]=" <<check[i] <<endl;
        }
        */
       if( m!=m1) {
           not_con=true;
       }
       //cout<<"mst_weight=" <<mst_weight<<endl;




    //checking disconnections looping throught check[] to find the ultimate parent (we can use sort for nlog n or simply n for lineat search, we want to do O(n)), if ultimate parent (aka the largest subset)
    //has less than m vertices, then there is a "disconnection"

}//end of mintree


    
    






    


