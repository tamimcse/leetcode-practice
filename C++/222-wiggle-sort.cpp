/*
https://leetcode.com/problems/wiggle-sort/
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        bool up = true;
        for (int i = 1; i < n; i++) {
            if ((up && nums[i] < nums[i-1]) || (!up && nums[i] > nums[i-1])) {
                swap(nums[i], nums[i-1]);
            }
            up = !up;
        }
    }
};
