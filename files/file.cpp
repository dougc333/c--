#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ofstream testfile;
  testfile.open("test.txt");
  testfile<<"this is in the file now";
  testfile.close();
  return 0;
}
