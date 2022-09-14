#include <iostream>
#include <vector>

#ifndef HASH_H
#define HASH_H

#include "info.h"
using namespace std; 

//forward declaration 

class info; 

class hasht{

long size;


public:
vector <info> hashtv; 
//the target number found by search or delete method
long* current; 
info* infocurrent;

long inserttrack;

//pointer for allocating new space of new info before inserting
 info* zz;
//pointer for modifying node
 info* x ;

void resizeinfo(long sizein);
void dhinsert(long numin, string user);
void dhdelete(long numin);
void  searchdh(long k);
void  chaininsert(long numin, string user);
void  cleanptr(info* current);
info*  findend(info* xx);
info* findfront(info* xx);
void  searchchain(long k);
void  insert(info* hashtvin, info* zz);
void print(long i) ;
void deletechain(long kk);
void sortchain(info* zz);



hasht();
~hasht();



};
#endif // HASH_H