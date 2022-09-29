/*
https://leetcode.com/problems/find-pivot-index/
*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0;
        int right = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            right += nums[i];
        }
        
        
        for (uint32_t i = 0; i < nums.size(); i++) {
            if (left == right) {
                return i;
            }
            left += nums[i];
            right -= (((i + 1) < nums.size()) ? nums[i+1] : 0);
        }
        return -1;
    }
};
