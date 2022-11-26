/*
https://leetcode.com/problems/maximum-product-subarray/
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> mindp(n);
        vector<int> maxdp(n);
        
        mindp[0] = nums[0];
        maxdp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            int a = nums[i] * mindp[i-1];
            int b = nums[i] * maxdp[i-1];
            mindp[i] = min(min (a, b), nums[i]);
            maxdp[i] = max(max (a, b), nums[i]);
        }
        
        int res = maxdp[0];
        for (int i = 1; i < n; i++) {
            res = max (res, maxdp[i]);
        }
        
        return res;
    }
};
