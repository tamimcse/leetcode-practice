/*
https://leetcode.com/problems/employee-importance/
*/
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

int calc_value (Employee *root, Employee **hash)
{
  int i, res = root->importance;
  
  for (auto e : root->subordinates) {
    res += calc_value (hash[e], hash);
  }
  return res;
}

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        Employee* hash[2000] = {NULL};
      
        for (auto e : employees) {
          hash[e->id] = e;
        }
      
        return calc_value (hash[id], hash);
    }
};
