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

using namespace std;

/* Main program */


string obenglobish(string word){
   cout<<"str length"<<word.length()<<endl;
   string temp="";
   for(int i=0;i<word.length();i++){
      cout<<"char:"<<word[i]<<endl;
      if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u'){
         temp.append("ob");
         temp.append(&word[i]);
      }else{
         temp.append(&word[i]);
      }
   } 

   return temp;
}

string scanString(string word){
  

}

int main(int argc, char** argv) {
   // [TODO: fill in the code]
   while(true){
      string word = getLine("Enter a word: ");
      if (word == "") 
	break;
      string trans = obenglobish(word);
      cout<<word<<"->"<<trans<<endl;
   }
   

   return 0;
}
