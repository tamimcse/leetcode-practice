/*
https://leetcode.com/problems/employee-importance/
*/
class Solution {
    int getImportance_inner (unordered_map<int, Employee*> &hash, int id) {
        Employee *e = hash[id];
        int sum = e->importance;

        for (auto e : e->subordinates) {
            sum += getImportance_inner(hash, e);
        }
        return sum;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> hash;
        
        for (auto &e : employees) {
            hash[e->id] = e;
        }
        
        return getImportance_inner(hash, id);
        
    }
};
