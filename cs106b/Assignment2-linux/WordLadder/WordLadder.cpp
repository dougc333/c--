/*
 * File: WordLadder.cpp
 * --------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the word ladder problem
 * on Assignment #2.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include "console.h"
#include "lexicon.h"
#include "queue.h"
#include "simpio.h"
#include "vector.h"
#include "lexicon.h"
using namespace std;

//ladder is vector of strings
Vector<string> findLadder(string startWord, string destWord){
   
   Vector<string > v; 
   Queue<Vector<string> > q;
   v.add(startWord);
   q.enqueue(v);
   while(q.size() > 0){
     Vector<string> ladder = q.dequeue();
     if(ladder.get(0)=="destWord"){
	return ladder;
     }
     //process words in ladder
     string processWord = ladder.dequeue();
     cout<<"processWord"<<processWord<<endl;
     //find the words which are 1 letter away
     Vector<string> v = findCloseWords(processWord);
   }
   return v;
}

void test(){
   Lexicon lex("EnglishWords.dat");
   cout<<"lex size: "<<lex.size()<<endl;
}

Vector<string> findCloseWords(string word){
    Lexicon lex("EnglishWords.dat");
    
    for(int i=0;i<word.length();i++){
       cout<<"replacing letter: "<<word[i]<<endl;
       for(int j=66;j<92;j++){
           
       }
    }
    
}

int main() {
	// [TODO: fill in the code]
 	test();
	Queue<string> queue;
	string startWord = getLine("Enter start word");
 	string destWord = getLine("Enter destination word");
	findLadder(startWord, destWord);
        //where is the start word? 
	return 0;
}
