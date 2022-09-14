/**
    ECE250
    playlist.h
    Purpose: Class playlist serves as a communicator between the users and the song class where data are stored. Multiple functions
    such as adding/ deleting songs and making play list array are member functions of the class.

    Author Eva Liu
    Version 1.0  - 16/01/2020
*/
#include <iostream>

using namespace std; 
//forward declearation
class song;

#ifndef PLAYLIST_H
#define PLAYLIST_H

class playlist {

private: 
int listSize=0;
int arrayIndex=0; 
int usedarrayIndex=0;
song* songList;
string s;
string a; 
//deallocate songlist from dynamic allocation memory. 



//constructor, playlist start with size 1 by default. 
public: 
playlist(const playlist &s);

//copy constructor
playlist();
/**
 Play the song in the song list by displaying the song's name and artist name as output.

  Params: 
   inputNum (in) - integer that specifies the order of the song in the array. (with 1 being the first song in the array
   such that song list [0] gives the first song stored in the array.)   

 */

void play(int inputNum);

/**
 Setting the size of the song list array of song type. 

  Params: 
   inputSize (in) - integer that specifies the size of the song list array, which is already a member variable.

 */

void set(int inputSize);

/**
 Adding  song and its artist into the list array of song type when no repitition is occured and the song list array still have 
 space to hold it. If the condition is not met, an message "can not insert" will be displayed. 

  Params: 
   s_in (in) - the song's name. 
   a_in (in) - the artist's name. 

 */

void add(string s_in, string a_in);


/**
 Erase a song from the play list array. (note: the order of the other song will stay the same.)

  Params: 
   index_input (in) - the order of the song 

 */

void erase(int index_input);

~playlist();

}; 

#endif // PLAYLIST_H

