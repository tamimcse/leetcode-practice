/*
https://leetcode.com/problems/maximum-subarray/
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int cur_max = nums[0];
        int max_with_last = nums[0];
        
        for (int i = 1; i < n; i++) {
            if (max_with_last > 0)
                max_with_last += nums[i];
            else
                max_with_last = nums[i];
            cur_max = max (cur_max, max_with_last);
        }

        return cur_max;
    }
};
