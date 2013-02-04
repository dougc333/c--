#include <stdio.h>

#ifndef hashtable_h
#define hashtable_h

struct hashentry{
   hashentry *next;
   hashentry *prev;
   int fd;
   int pagenum;
   int slot;
};


class hashtable{
public:
   hashtable(int numBuckets);
   ~hashtable(); 
   int hash(int fd, int pageNum, int slot);
   int find(int fd, int pageNum, int slot);
   int insert( int fd, int pageNum, int slot);
   int delete(int fd, int pageNum);

private:
   hashentry ** hashTable;   

};
