/*
https://leetcode.com/problems/single-element-in-a-sorted-array/
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        int mid;

        while (start <= end) {
            mid = (start + end) >> 1;
            if (mid < end && nums[mid + 1] == nums[mid]) {
                mid++;
                if ((mid - start + 1) & 1) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else if (mid > start && nums[mid] == nums[mid - 1]) {
                if ((mid - start + 1) & 1) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                return nums[mid];
            }
        }
        return -1;
    }
};
