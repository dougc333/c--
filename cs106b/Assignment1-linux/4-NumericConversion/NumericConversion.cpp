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

<<<<<<< HEAD

=======
>>>>>>> 62b7524b06bb343203dfa4f9c5956faa01a3d73d
using namespace std;

/* Function prototypes */

string intToString(int n);
int stringToInt(string str);

<<<<<<< HEAD


//recursive implementation 
string intToString(int n){
  if(n/10<1){
      return integerToString(n);
  }
  int num = n/10;
  int rem = n%10;
  
  string temp = intToString(num)+integerToString(rem);
  return temp;
}


//recursive implementation
int strintToInt(string str){


}

/* Main program */

int main() {
   // [TODO: fill in the code]
   cout<<"intToString(1443): "<<intToString(1443)<<endl;
   cout<<"intToString(1449): "<<intToString(1449)<<endl;
   cout<<"intToString(1): "<<intToString(1)<<endl;
  
=======
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

>>>>>>> 62b7524b06bb343203dfa4f9c5956faa01a3d73d
   return 0;
}
