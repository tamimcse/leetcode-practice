/*
https://leetcode.com/problems/combination-sum-iv/
*/
class Solution {
    int combinationSum4_inner(vector<int>& nums, int target, unordered_map<int, int> &hash) {
        int count = 0, ret;
        
        if (hash.find(target) != hash.end())
            return hash[target];
        
        if (!target)
            return 1;
        
        for (auto e : nums) {
            if (e > target)
                continue;
            ret = combinationSum4_inner(nums, target - e, hash);
            hash[target - e] = ret;
            count += ret;
        }
        return count;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        
        return combinationSum4_inner(nums, target, hash);
    }
};
