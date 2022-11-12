/*
https://www.geeksforgeeks.org/minimum-maximum-values-expression/
*/
#include <iostream>
#include <string>
using std::cout;
using std::string;
using std::endl;

int max_value(string s) {
  return 1;
}

int main() {
  string s = "1*3+3*5+5+5*6";
  cout << max_value (s) << endl;
}
