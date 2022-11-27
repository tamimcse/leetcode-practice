/*
https://leetcode.com/problems/search-in-rotated-sorted-array/
*/
class Solution {
    int binary_search (vector<int>& nums, int start, int end, int target) {
        int mid;
        
        while (end >= start) {
            mid = (start + end) >> 1;
            if (nums[mid] == target)
                return mid;
            if (target > nums[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, mid;
        
        if (nums.back() >= nums[0])
            return binary_search (nums, 0, nums.size() - 1, target);
        
        int smallest;
        while (end >= start) {
            mid = (start + end) >> 1;
            if (mid > 0 && nums[mid] < nums[mid-1]) {
                smallest = mid;
                break;
            }
            if (nums[mid] < nums.back()) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        cout << smallest;
        int idx;
        idx = binary_search (nums, smallest, nums.size() - 1, target);
        if (idx != -1)
            return idx;
        return binary_search (nums, 0, smallest - 1, target);;
    }
};
