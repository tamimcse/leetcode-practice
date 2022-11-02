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
    void subsets_inner(vector<int>& nums, 
                       unordered_set<vector<int>, HashFunc> &us, vector<vector<int>> &res) {
        int n = nums.size();
        
        if (us.count(nums))
            return;
        
        res.push_back(nums);
        us.insert(nums);
        
        if (n == 1)
            return;
        
        for (int i = 0; i < n; i++) {
            int tmp = nums[i];
            nums.erase(nums.begin() + i);
            subsets_inner(nums, us, res);
            nums.insert(nums.begin() + i, tmp);
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> valid(n);
        unordered_set<vector<int>, HashFunc> us;
        
        res.push_back(vector<int>());
        subsets_inner(nums, us, res);
        return res;
    }
};
