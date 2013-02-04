#include <iostream>
#include <fstream>

int main(){
  ofstream testfile;
  testfile.open("test.txt");
  testfile<<"this is in the file now"<<endl;
  testfile.close();
  return 0;
}
