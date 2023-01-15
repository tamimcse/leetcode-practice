/*
https://www.geeksforgeeks.org/given-array-strings-find-strings-can-chained-form-circle/

I think, we can use simple DFS to detect cycle. After detecting cycle, we need to check the length of the cycle to see if all the nodes have been visited.

I havn't implemented it.

*/
#include <iostream>
#include <vector>
using std::cout; using std::endl; using std::vector;

bool can_form_cycle (vector<string> strs) {
  int n = strs.size();
  vector<vector<string>> adj_list(n);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;
      if (strs[i].back() == strs[j].front())
        adj_list[i].push_back(strs[j]);	
    }
  }
  
  
}

int main () {
  vector<string> input = {"for", "geek", "rig", "kaf"};
  
  bool res = can_form_cycle (input);
  cout << res << endl;
} 
