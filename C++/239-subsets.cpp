/*
https://leetcode.com/problems/subsets/
*/
struct HashFunc {
    int operator()(const vector<int> &v) const {
        long long sum = 0;
        
        for (auto e : v)
            sum += e;
        return sum;
    }    
};

class Solution {
    vector<int> create_res(vector<int>& nums,
                           vector<int>& valid) {
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i++) {
            if (!valid[i])
                res.push_back(nums[i]);
        }
        return res;
    }
    void subsets_inner(vector<int>& nums, vector<int>& valid,
                       unordered_set<vector<int>, HashFunc> &us, 
                       int count_dash, vector<vector<int>> &res) {
        int n = nums.size();
        
        vector<int> ret = create_res(nums, valid);
        if (!us.count(ret)) {
            res.push_back(ret);
            us.insert(ret);
        }
            
        if (count_dash == n - 1)
            return;
        
        for (int i = 0; i < n; i++) {
            if (valid[i])
                continue;
            valid[i] = 1;
            subsets_inner(nums, valid, us, count_dash + 1, res);
            valid[i] = 0;
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> valid(n);
        unordered_set<vector<int>, HashFunc> us;
        
        res.push_back(vector<int>());
        subsets_inner(nums, valid, us, 0, res);
        return res;
    }
};
