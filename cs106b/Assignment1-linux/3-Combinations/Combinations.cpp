/*
 * File: Combinations.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the recursive combinations problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
using namespace std;

<<<<<<< HEAD
int main() {
   // [TODO: fill in the code]
=======
int factorial(int n){
   if (n==0)
     return 1;
   if(n==1){
     return 1;
   }
   int num = n*factorial(n-1);
   return num;
}

void factorialTest(){
  cout<<"factorial test"<<factorial(4)<<endl;
}

//n!/k!(n-k)!
double comboFormula(int n, int k){
   return factorial(n)/(factorial(k)*factorial(n-k));
}

int main() {
   cout<<"computing C(n,k) = n!/k!(n-k)!"<<endl;
   int c = getInteger("Enter in n: ");
   int k = getInteger("Enter in k: ");
   while(1){
     if(c<k){
      cout<<"error, c must be > k"<<endl;
      int c = getInteger("Enter in n");
      int k = getInteger("Enter in k");
     }else{
      cout<<"combination: "<<comboFormula(c,k)<<endl;
      break;
     }
   }
   
>>>>>>> 62b7524b06bb343203dfa4f9c5956faa01a3d73d
   return 0;
}
