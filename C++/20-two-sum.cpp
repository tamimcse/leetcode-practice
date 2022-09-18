/*
https://leetcode.com/problems/two-sum/
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        unordered_map<int, int> hash;
        
        for (int i = 0; nums.size(); i++) {
            auto it = hash.find(target - nums[i]);
            if (it != hash.end()) {

                v.push_back(i);
                v.push_back(it->second);
                return v;
            } else {
                hash.insert(make_pair(nums[i], i));
            }
        }
        
        return v;
    }
};
