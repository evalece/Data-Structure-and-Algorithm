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


using namespace std; 
//class song stores two data- song name and artist
class song {
private:
 string songx;
 string artistx; 

song() {
  
}

song ( string  e,  string ee)  {

  this->songx = e;
  this->artistx = ee; 
}

~song(){

}

 public:
 friend class playlist; 


};



class playlist {

private: 
int listSize;
int arrayIndex=0; 
song* songList;
string s;
string a; 
//constructor, playlist must be initialize with input array size. 
public: 

playlist( ) {
cout<< "Please input array size" <<endl;
}

playlist( int inputSize) {
listSize= inputSize; 
songList= new song[listSize];
}

void add(string s_in, string a_in) {
s=s_in;
a=a_in;
songList[arrayIndex]= song(s,a);
arrayIndex++; 
cout<< "success" <<endl;
}


//deallocate songlist from dynamic allocation memory. 
~playlist(){
  delete [] songList;
  cout<< "destruction done." <<endl;
}

}; 



int main(int argc, char* argv[]){

//parsing user inputs and run only one line at the time:
string str= argv[1];
string filename_no_in= str.substr(0, str.find(".in"));
cout<< filename_no_in <<endl;


  string line;
  string command;
  int playlist_size;
  //s = song name
  string s;
  //a = artist
  string a;
  // n = position of the song
  int n; 


  ifstream myfile (argv[1]);
  if (myfile.is_open())
  {
    
    int linenum=0;

    //reading array size from input
    if (linenum=0){
    while ( getline (myfile,line) )
      {    

     if (line.find("m ")==0) {
            linenum++;
            command="m"; 
            playlist_size= stoi(line.substr(2, line.length()));
            cout<< command<<endl;
            cout << command <<endl;
            cout << playlist_size<<endl;

          }
       }
     }

       //initialize playlist
        playlist o1(playlist_size); 


      while ( getline (myfile,line) )
      {    
          if (line.find("i ")==0) {
             command="i";
             s= line.substr(2,line.find(";")-2);
             a= line.substr(line.find(";")+1,line.length());
             cout<< command<<endl;
             cout<< s <<endl;
             cout<< a <<endl;
             //o1.add(s,a);
            }

          if (line.find("p ")==0) {
             command="p";
             n= stoi(line.substr(2, line.length()));
             cout<< command<<endl;
             cout<< n<< endl;

            }

          if (line.find("e ")==0) {
             command="e";
             n= stoi(line.substr(2, line.length()));
             cout<< command<<endl;
             cout<< n <<endl;
              } 
   }
  


    myfile.close();
  }

 return 0;

}

/*

  //outputing to file
  ofstream outputFile("program3data.txt");
//...
outputFile << "writing to file";
*/

   
