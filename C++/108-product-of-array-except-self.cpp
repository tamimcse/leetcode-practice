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

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long prod;        
        vector<int> res(nums.size());
        vector<int> left(nums.size());
        vector<int> right(nums.size());
        
        prod = 1;
        left[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            prod *= nums[i - 1];
            left[i] = prod; 
        }
        
        prod = 1;
        right[nums.size() - 1] = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            prod *= nums[i + 1];
            right[i] = prod; 
        }
        
        for (int i = 0; i < nums.size(); i++) {
            res[i] = left[i] * right[i];
        }
        return res;
    }
};
