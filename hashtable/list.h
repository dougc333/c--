#include <stdio.h>


struct node{
   int nodeNum;
   node *next;
   node *prev;
};


class list{
  public: 
     void list();
     ~list();
     insert(node *node);
     delete(node *node);
     find(int findMe);
}    

