/*
 * File: ConsecutiveHeads.cpp
 * --------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the coin-flipping problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
<<<<<<< HEAD
#include <stdio.h>
#include <string>
#include "console.h"
#include "random.h"
using namespace std;

int main() {
   // [TODO: fill in the code]
   int random=0; 
   int numHeads=0;	
   int numTails= 0;
   
   while(1){
     random = randomInteger(0,2);
     printf("random:%d \n",random);
     if(random<=1){
       printf("heads\n");
       numHeads++;
       if(numHeads>=3){
         break;
       }
     }else{
       printf("tails\n");
       numTails++;
     }
   }
   printf ("numHeads:%d out of total:%d", numHeads, (numHeads+numTails));
=======
#include <string>
#include "console.h"
#include "random.h"
#include "simpio.h"
#include "strlib.h"

using namespace std;

int main(int argc, char** argv) {

   int numHeads=0;
   int numTails=0;
   while(numHeads<3){
    string ht = getLine("Enter in H/T:");
    if (equalsIgnoreCase("H",ht)){
      cout<<"h"<<endl;
      numHeads++;
    } else if (equalsIgnoreCase("T",ht)){
     cout<<"t"<<endl;
     numTails++;
    }
   }
   cout<<"there are"<<numTails<<" and numHeads:"<<numHeads<<" "<<endl;
 
>>>>>>> 62b7524b06bb343203dfa4f9c5956faa01a3d73d
   return 0;
}
