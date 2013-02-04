/**
 * File: rsg.cc
 * ------------
 * Provides the implementation of the full RSG application, which
 * relies on the services of the built-in string, ifstream, vector,
 * and map classes as well as the custom Production and Definition
 * classes provided with the assignment.
 */
 
#include <map>
#include <fstream>
#include <vector>
#include <cassert>
#include "definition.h"
#include "production.h"
using namespace std;


static const size_t LINE_MAX_CHARS = 70;
static const size_t NUM_VERSIONS = 3;
static const string PUNCT_MARKS[] = {".", ",", "!", "?", ";" ":"};


string expandDefinition(string definitionTitle, map<string, Definition>& grammar);
bool isNonTerminal(const string& str);
void recursiveExpandDef(Definition& def, map<string, Definition>& grammar, vector<string>& builder);
string expandWordVector(const vector<string>& builder);
void runExpansion(map<string, Definition>& grammar);
bool isPunctuation(const string & str);

/**
 * Takes a reference to a legitimate infile (one that's been set up
 * to layer over a file) and populates the grammar map with the
 * collection of definitions that are spelled out in the referenced
 * file.  The function is written under the assumption that the
 * referenced data file is really a grammar file that's properly
 * formatted.  You may assume that all grammars are in fact properly
 * formatted.
 *
 * @param infile a valid reference to a flat text file storing the grammar.
 * @param grammar a reference to the STL map, which maps nonterminal strings
 *                to their definitions.
 */

static void readGrammar(ifstream& infile, map<string, Definition>& grammar)
{
  while (true) {
    string uselessText;
    getline(infile, uselessText, '{');
    if (infile.eof()) return;  // true? we encountered EOF before we saw a '{': no more productions!
    infile.putback('{');
    Definition def(infile);
    grammar[def.getNonterminal()] = def;
  }
}

/**
 * Performs the rudimentary error checking needed to confirm that
 * the client provided a grammar file.  It then continues to
 * open the file, read the grammar into a map<string, Definition>,
 * and then print out the total number of Definitions that were read
 * in.  You're to update and decompose the main function to print
 * three randomly generated sentences, as illustrated by the sample
 * application.
 *
 * @param argc the number of tokens making up the command that invoked
 *             the RSG executable.  There must be at least two arguments,
 *             and only the first two are used.
 * @param argv the sequence of tokens making up the command, where each
 *             token is represented as a '\0'-terminated C string.
 */

int main(int argc, char *argv[])
{
  if (argc == 1) {
    cerr << "You need to specify the name of a grammar file." << endl;
    cerr << "Usage: rsg <path to grammar text file>" << endl;
    return 1; // non-zero return value means something bad happened 
  }
  
  ifstream grammarFile(argv[1]);
  if (grammarFile.fail()) {
    cerr << "Failed to open the file named \"" << argv[1] << "\".  Check to ensure the file exists. " << endl;
    return 2; // each bad thing has its own bad return value
  }
  
  // things are looking good...
  map<string, Definition> grammar;
  readGrammar(grammarFile, grammar);
  cout << "The grammar file called \"" << argv[1] << "\" contains "
       << grammar.size() << " definitions." << endl;
  
  for(size_t i = 1; i <= NUM_VERSIONS; i++){
    cout << "Version #" << i << ": ";
    for (size_t j = 0; j < LINE_MAX_CHARS - 11; j++) cout << "-";
    cout << endl;
    runExpansion(grammar);
    cout << endl << endl;
  }
  return 0;
}

void runExpansion(map<string, Definition>& grammar){
  string expansion = expandDefinition("<start>", grammar);
  cout << expansion << endl;
}

string expandDefinition(string definitionTitle, map<string, Definition>& grammar){
  map<string, Definition>::iterator start = grammar.find(definitionTitle);
  assert(start != grammar.end());
  Definition def = start->second;
  vector<string> builder = vector<string>();
  recursiveExpandDef(def, grammar, builder);
  string returnString = expandWordVector(builder);
  return returnString;
}


/**
 * Recursively expands a definition and adds the string entries to a vector
 * @param def The definition to be expanded
 * @param grammar The grammar of which the definition is a member
 * @param builder The vector to which the strings should be added
 *
 */

void recursiveExpandDef(Definition& def, map<string, Definition>& grammar, vector<string>& builder){
  Production prod = def.getRandomProduction();
  for (Production::iterator curr = prod.begin(); curr != prod.end(); ++curr){
    if(isNonTerminal(*curr)){
	map<string, Definition>::iterator found = grammar.find(*curr);
	assert(found != grammar.end());
	recursiveExpandDef(found->second, grammar, builder);
      } else {
      builder.push_back(*curr);
      }
  }
}

  /**
   * returns whether the entry in a given definition is non-terminal
   *
   *
   */

bool isNonTerminal(const string& str){
  return str[0] == '<' && str[str.length() - 1] == '>';
}

string expandWordVector(const vector<string>& builder){
  string lineBuilder = "";
  string builderString = "";
  for (size_t i = 0; i < builder.size(); i++){
    if(lineBuilder.length() + builder[i].length() > LINE_MAX_CHARS){
       builderString = builderString + "\n" + lineBuilder;
       lineBuilder = "";
     }
    string spacer = " ";
    if (isPunctuation(builder[i])) spacer = "";
    lineBuilder = lineBuilder + spacer + builder[i];
  }
  builderString = builderString + "\n" + lineBuilder;
  return builderString;
}

bool isPunctuation(const string & str){
  for(size_t i = 0; i < sizeof(PUNCT_MARKS) / sizeof(PUNCT_MARKS[0]); i++){
      if(str.compare(PUNCT_MARKS[i]) == 0) return true;
    }
    return false;
}
