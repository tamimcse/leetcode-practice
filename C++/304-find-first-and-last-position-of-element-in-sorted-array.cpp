/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), start = 0, end = n - 1, mid;
        int high, low;
        vector<int> res;
    
        while (start <= end) {
            mid = (start + end) >> 1;
            if (target > nums[mid]) {
                start = mid + 1;
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else {
                high = mid;
                low = mid;
                while (high + 1 < n && nums[high + 1] == nums[high])
                    high++;
                while (low - 1 >= 0 && nums[low - 1] == nums[low])
                    low--;
                res.push_back(low);
                res.push_back(high);
                return res;
            }
        }
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
};
