/*
https://leetcode.com/problems/product-of-array-except-self/

Implement it using and without division operator
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long prod = 1;        
        int count_zero = 0;
        vector<int> res;
        res.resize(nums.size());
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i])
                prod *= nums[i];
            if(!nums[i])
                count_zero++;
        }
        
        if (count_zero > 1) {
            for (int i = 0; i < nums.size(); i++) {
                res[i] = 0;
            }   
            return res;
        }
        
        if (count_zero == 1) {
            for (int i = 0; i < nums.size(); i++) {
                res[i] = (nums[i] != 0) ? 0 : prod;
            }
            return res;            
        }
        
        for (int i = 0; i < nums.size(); i++) {
            res[i] = prod/nums[i];
        }
        return res;
    }
};
