/*
https://leetcode.com/problems/sort-array-by-parity/
*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int odd_idx = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & 1) {
                odd_idx = i;
                break;
            }
        }
            
        for (int i = 0; i < nums.size(); i++) {
            if(((nums[i] & 1) == 0) && (i > odd_idx) && (odd_idx >= 0)) {
                swap(nums[i], nums[odd_idx]);
                odd_idx++;
                while (odd_idx < nums.size() && (nums[odd_idx] % 2) == 0)
                    odd_idx++;
            }
        }
        
        return nums;
    }
};
