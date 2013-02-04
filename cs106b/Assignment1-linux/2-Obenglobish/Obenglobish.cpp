/*
 * File: Obenglobish.java
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Obenglobish problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
#include "tokenscanner.h"
#include <stdio.h>

using namespace std;

/* Main program */

string obenglobish(string inputLine){
  TokenScanner scanner(inputLine); 
  scanner.scanStrings();
  while(scanner.hasMoreTokens()){
    char token = scanner.getChar();
    //printf("%d\n",token);
    cout<<"token:"<<token<<endl;
    return "here";
  }
  return "asdf";
}

int main(int arg, char**argv) {
   while(1){
     string input = getLine("Enter a word");
     if(input=="") break;
     cout<<"input"<<input<<endl;
     string obString = obenglobish(input);
     cout<< "word: "<<input << "->" << obString << endl;  
     break;
   }
   return 0;
}


