/*
https://leetcode.com/problems/longest-increasing-subsequence/
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> count(nums.size());
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    count[i] = max(count[i], count[j] + 1);
            }
            if (!count[i])
                count[i] = 1;
        }
        
        int max = 0;
        for (int i = 0; i < count.size(); i++) {
            if (count[i] > max)
                max = count[i];
        }
        return max;
    }
};
