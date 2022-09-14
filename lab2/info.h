#include <iostream>

using namespace std; 

#ifndef info_H
#define info_H

class info {

public:
//for chain and linked list:
info* prev =nullptr; 
info* next=nullptr;
string user;
long phone; 


//contains information for user and phone number
info(long numin, string userin);
info();
//copy constructor
info(const info &p2);
~info();


};

#endif // info_H