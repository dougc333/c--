/*
 * File: ConsecutiveHeads.cpp
 * --------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the coin-flipping problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
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
   return 0;
}
