/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int to_insert = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[to_insert++] = nums[i];
            }
        }
        return to_insert;
    }
};
