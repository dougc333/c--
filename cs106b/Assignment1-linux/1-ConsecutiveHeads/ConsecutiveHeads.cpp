/*
 * File: ConsecutiveHeads.cpp
 * --------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the coin-flipping problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
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
 
   return 0;
}
