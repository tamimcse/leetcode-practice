/*
https://leetcode.com/problems/product-of-array-except-self/

Implement it without division operator and using extra space and without extra space
*/

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

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        res[0] = 1;
        int mul = 1;
        for (int i = 1; i < n; i++) {
            mul = mul * nums[i-1];
            res[i] = mul;
        }

        mul = 1;
        for (int i = n - 2; i >= 0; i--) {
            mul = mul * nums[i+1];
            res[i] =res[i] * mul;
        }
        
        return res;
    }
};
