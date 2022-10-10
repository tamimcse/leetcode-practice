/*
https://leetcode.com/problems/maximum-average-subarray-i/
*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0, max;
        
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
    
        max = sum;
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];
            if (sum > max)
                max = sum;
        }
        
        return (double)max/k;
    }
};
