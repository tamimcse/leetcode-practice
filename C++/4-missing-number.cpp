/*
https://leetcode.com/problems/missing-number/
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, len = nums.size();
        for (auto e : nums) {
            sum += e;
        }
        return ((len * (len + 1)) >> 1) - sum;
    }
};
