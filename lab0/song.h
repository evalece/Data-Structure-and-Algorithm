/**
    ECE250
    song.h
    Purpose: Class to store song name and artist where the right to retrieve or/and store is given to the friend class playlist.

    Author Eva Liu
    Version 1.0  - 16/01/2020
*/

#include <iostream>
#include "playlist.h"
using namespace std; 
//class song stores two data- song name and artist
class song {
private:
 playlist a;
 string songx="user_did_not_provide_input";
 string artistx="user_did_not_provide_input"; 


 public:
 friend class playlist; 
 //copy constructor
 song();
 song (string  e,  string ee);
 ~song();
 song(const song &c);

};