/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/submissions/
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        if (nums[0] < nums[n-1])
            return nums[0];

        if (nums[0] == nums[n-1]) {
            int count = 1;
            for (int i = 1; i < n; i++) {
                if (nums[i] != nums[0])
                    break;
                count++;
            }
            if (count == n)
                return nums[0];
        }

        int start = 0, end = n - 1, mid;
        while (start <= end) {
            mid = (start + end) >> 1;
            if (nums[mid] > nums[end]) {
                if (nums[mid] > nums[mid+1])
                    return nums[mid+1];
                start = mid + 1;
            } else if (nums[mid] < nums[end]) {
                if (nums[mid] < nums[mid-1])
                    return nums[mid];
                end = mid;
            } else {
                if (end > 0 && nums[end-1] <= nums[end])
                    end--;
                else
                    start++;
            }
        }
        return 0;
    }
};
