/*
https://leetcode.com/problems/two-sum/
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> res(2);
            
        for (int i = 0; i < nums.size(); i++) {
            auto it = hash.find(target - nums[i]);
            if (it != hash.end()) {
                res[0] = i;
                res[1] = it->second;
                return res;
            } else {
                hash[nums[i]] = i;
            }
        }
        return res;
    }
};
