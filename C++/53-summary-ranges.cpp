/*
https://leetcode.com/problems/summary-ranges/
*/
class Solution {
    string format (vector<int>& nums, int start, int end) {
        if (start == end) {
            return to_string(nums[start]);
        } else {
            return to_string(nums[start]) + "->" + to_string(nums[end]);
        }        
    }
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        
        int start = 0, end = 0;
        
        if (nums.empty())
            return res;
        
        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] != nums[i - 1] + 1)) {
                res.push_back (format(nums, start, end));
                start = i;
                end = i;
            } else {
                end++;
            }
        }
        res.push_back (format(nums, start, end));
        return res;
    }
};
