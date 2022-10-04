/*
https://leetcode.com/problems/missing-ranges/
*/
class Solution {
    string range(int start, int end) {
        if (start == end)
            return to_string(start);
        else
            return to_string(start) + "->" + to_string(end);
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        
        if (nums.size() == 0) {
            res.push_back(range(lower, upper));
            return res;
        }

        if (nums[0] > lower) {
            res.push_back(range(lower, nums[0] - 1));
        }
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1] + 1)
                res.push_back(range(nums[i-1] + 1, nums[i] - 1));
        }
        
        if (nums.back() < upper) {
            res.push_back(range(nums.back() + 1, upper));
        }
        
        return res;
    }
};
