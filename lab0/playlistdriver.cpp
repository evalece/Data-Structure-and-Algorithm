/**
    ECE250
    playlistdriver.cpp
    Purpose: Parsing user inputs and catch unexpected inputs. 
    Provides services to modify playlist which contains songs with functions like set, add, play, erase from playlist.

    Author Eva Liu
    Version 1.0  - 11/01/2020
*/

#include <iostream>
#include <fstream>
#include <string>
#include "song.h"
#include "playlist.h"


int main(){

//parsing user inputs and run only one line at the time:

  string line; //reading line by line from input file.
  string command; //the parsed command. 
  int playlist_size;
 
  string s; //song name
  string a; //artist
  int n;  //position of the song

  
     playlist o1; 
   
    //reading array size from input 
    while ( getline (cin,line) ){ // from <string> - http://www.cplusplus.com/reference/string/string/getline/
          
     if (line.find("m ")==0) {          
            command="m"; 
            playlist_size= stoi(line.substr(2, line.length()));
            o1.set(playlist_size);
          }

          if (line.find("i ")==0) {
             command="i";
             s= line.substr(2,line.find(";")-2);
             a= line.substr(line.find(";")+1,line.length());
             o1.add(s,a);
      
            }

          if (line.find("p ")==0) {
             
             command="p";
             n= stoi(line.substr(2, line.length()));
             o1.play(n);
            }

          if (line.find("e ")==0) {
             command="e";
             n= stoi(line.substr(2, line.length()));            
             o1.erase(n);
             }   

           if(!line.find("e ")==0 && !line.find("p ")==0 &&!line.find("i ")==0 && !line.find("m ")==0) {
              cout<< "the command is not defined." <<endl;
          }


        }
      
   return 0;
}


   
