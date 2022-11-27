/*
https://leetcode.com/problems/permutations/
*/
class Solution {
    void permute_inner(vector<int>& nums, vector<int>& visited, 
                                      vector<int> &res, int to_insert, vector<vector<int>> &actaul_res) {
        if (to_insert ==  nums.size()) {
            actaul_res.push_back(res);
            return;
        } 
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i])
                continue;
            res[to_insert++] = nums[i];
            visited[i] = 1;
            permute_inner(nums, visited, res, to_insert, actaul_res);
            to_insert--;
            visited[i] = 0;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> actaul_res;
        vector<int> res(nums.size());
        vector<int> visited(nums.size());
        
        permute_inner (nums, visited, res, 0, actaul_res);
        return actaul_res;
    }
};
