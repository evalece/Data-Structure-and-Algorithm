/**
    ECE250
    song.cpp
    Purpose: Class to store song name and artist where the right to retrieve or/and store is given to the friend class playlist.

    Author Eva Liu
    Version 1.0  - 16/01/2020
*/

#include <iostream>
#include "song.h"
using namespace std; 
//class song stores two data- song name and artist

song::song() {}
song::song ( string  e="user_did_not_provide_input",  string ee="user_did_not_provide_input")  {

  this->songx = e;
  this->artistx = ee; 
}
 song::~song(){}
 
 //copy constructor
 song::song(const song &c) {
   songx = c.songx; artistx = c.artistx; 
   }
