/*
 * File: NumericConversion.cpp
 * ---------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the numeric-conversion problem
 * in which you implement the functions intToString and stringToInt.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <string>
#include "console.h"
#include "strlib.h"

using namespace std;

/* Function prototypes */

string intToString(int n);
int stringToInt(string str);

/* Main program */


string intToString(int n){
  if(n/10 < 1){
     return integerToString(n%10);
  }
  cout<<"greater than 10"<<(n/10)<<endl;
  cout<<"remainder"<<(n%10)<<endl;
  //add 2 strings together
  
  return "asdf";
}

int stringToInt(string str){

}

int main() {
   // [TODO: fill in the code]
   cout<<"intToString(4): "<<intToString(4)<<endl;  
   cout<<"intToString(44): "<<intToString(44)<<endl;  

   return 0;
}
