/**
    ECE250
    playlist.cpp
    Purpose: Class playlist serves as a communicator between the users and the song class where data are stored. Multiple functions
    such as adding/ deleting songs and making play list array are member functions of the class.

    Author Eva Liu
    Version 1.0  - 16/01/2020
*/

#include <iostream>
#include "playlist.h"
#include "song.h"
using namespace std; 


//constructor, playlist start with size 1 by default. 
playlist::playlist(const playlist &s) {
delete [] songList;
listSize=s.listSize;
arrayIndex=s.arrayIndex; 
usedarrayIndex=s.usedarrayIndex;
songList= new song[listSize];
//copying array of song in song list
for (int i=0; i< listSize; i++) {
    songList[i] =s.songList[i];
   }

}

//copy constructor
playlist::playlist() {
songList= new song[0];
}

/**
 Play the song in the song list by displaying the song's name and artist name as output.

  Params: 
   inputNum (in) - integer that specifies the order of the song in the array. (with 1 being the first song in the array
   such that song list [0] gives the first song stored in the array.)   

 */

 void playlist::play(int inputNum) {

  const int arraynum= inputNum-1;

  if (songList[arraynum].songx=="user_did_not_provide_input" && songList[arraynum].artistx=="user_did_not_provide_input") {
    cout<<"can not play " <<inputNum<<endl;
    }
  else{
    cout<<"played " << inputNum << " "<<songList[arraynum].songx<<";"<<songList[arraynum].artistx<< endl; 
   }

}

/**
 Setting the size of the song list array of song type. 

  Params: 
   inputSize (in) - integer that specifies the size of the song list array, which is already a member variable.

 */

void playlist::set(int inputSize) {
listSize= inputSize; 
delete[] songList;
songList= new song[listSize];
cout<< "success" << endl;
}


/**
 Adding  song and its artist into the list array of song type when no repitition is occured and the song list array still have 
 space to hold it. If the condition is not met, an message "can not insert" will be displayed. 

  Params: 
   s_in (in) - the song's name. 
   a_in (in) - the artist's name. 

 */

void playlist::add(string s_in, string a_in) {
s=s_in;//song name 
a=a_in;//artist name

string emptys=s_in;
string emptya=a_in;
bool repeated= false; //repitition flag
bool empty_s_or_a =false;// whitespace flag 

for(int i =0; i <s.length();i++ ) {

  int k=0;
  if (s[i]==' '){
    k++;
    if(k==s.length()-1) {
      empty_s_or_a =true;
    }
  }
}

//checking artist input if song input is given
if(empty_s_or_a ==false) {

  for(int i =0; i <a.length();i++ ) {

  int k=0;
  if (a[i]==' '){
    k++;
    if(k==a.length()-1) {
      empty_s_or_a =true;
     }
    }
  }
}



//if inputs are not empty, write inputs into the function.
if(!s.empty() && !a.empty() && empty_s_or_a ==false) { /// from <string> - http://www.cplusplus.com/reference/string/string/empty/

      for (int i=0; i<arrayIndex;i++){
      //checking if repition occurs.
      if (s==songList[i].songx && a==songList[i].artistx) {
        repeated= true;
        cout<<"can not insert "<< s <<";"<< a <<endl;
          }
        }

      // checking if the array still have space to hold the input song.
      if(arrayIndex<listSize && repeated==false ){
      songList[arrayIndex]= song(s,a);
      arrayIndex++;
      cout<< "success" <<endl;
        }
        
}

//if one or two of the above condition is not met, an error message will be displayed.  
  else{
    cout<<"can not insert "<< s <<";"<< a <<endl;
  }

}

/**
 Erase a song from the play list array. (note: the order of the other song will stay the same.)

  Params: 
   index_input (in) - the order of the song 

 */

void playlist::erase(int index_input){
//checking if the song has been modified. (note: song and artist are assigned to "user_did_not_provide_input" before the user uses it.)
if(songList[index_input-1].songx!="user_did_not_provide_input" && index_input< listSize){
  songList[index_input-1].songx= "user_did_not_provide_input";
  songList[index_input-1].artistx= "user_did_not_provide_input";
  cout<< "success" <<endl;
  for (int i = index_input-1; i< listSize-1; i++) {

    if(songList[i+1].songx!= "user_did_not_provide_input" && songList[i+1].artistx!= "user_did_not_provide_input"){
      songList[i]=songList[i+1];
      songList[i+1].songx= "user_did_not_provide_input";
      songList[i+1].artistx= "user_did_not_provide_input";

      //cout<< songList[i].songx<< endl;
      
    }

  }

  }

  else{
      cout<< "can not erase " << index_input << endl;
  }

}


//deallocate songlist from dynamic allocation memory. 
playlist::~playlist(){
   songList=NULL;
  delete[] songList;
}

