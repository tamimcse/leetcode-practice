/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];
        if (n <= 2)
            return *min_element(nums.begin(), nums.end());

        if (nums[0] < nums[n-1])
            return nums[0];

        int mid, start = 0, end = n - 1;
        while (start <= end) {
            mid = (start + end) >> 1;
            if (nums[mid] > nums[0]) {
                if (nums[mid + 1] < nums[mid])
                    return nums[mid + 1];
                start = mid + 1;
            } else {
                if (mid == 0) {
                    return nums[1];
                }
                if (nums[mid - 1] > nums[mid])
                    return nums[mid];
                end = mid - 1;
            }
        }
        return 0;
    }
};
