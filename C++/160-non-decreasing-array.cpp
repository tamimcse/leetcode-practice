/*
https://leetcode.com/problems/non-decreasing-array/
*/
class Solution {
    bool isNonDecreasing (vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }            
        }
        return true;
    }
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                int tmp = nums[i];
                nums[i] = nums[i - 1];
                if (isNonDecreasing(nums))
                    return true;
                nums[i] = tmp;
                nums[i - 1] = tmp;
                return isNonDecreasing(nums);
            }
        }
        return true;
    }
};
