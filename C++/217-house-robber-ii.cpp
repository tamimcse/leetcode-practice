/*
https://leetcode.com/problems/house-robber-ii/
*/
class Solution {
    int rob_linear(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        
        if (n == 0)
            return 0;
        
        if (n == 1)
            return nums[0];
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max (dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[n-1];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int last = nums.back();
        nums.pop_back();
        int max1 = rob_linear(nums);
        nums.push_back(last);
        nums.erase(nums.begin());
        return max (max1, rob_linear(nums));
    }
};
