/*
https://leetcode.com/problems/search-in-rotated-sorted-array/
*/
class Solution {

public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        int mid;
        
        while (start <= end) {
            mid = (start + end) >> 1;
            if (nums[mid] == target)
                return mid;
            //the whole range is a strainght line
            if (nums[end] > nums[start]) {
                if (target > nums[mid]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else {//the whole range has two straight lines
                if (target >= nums[start]) {//target is in the first part
                    if (nums[mid] >= nums[start] ) {//mid is in the first part
                        if (target > nums[mid]) {
                            start = mid + 1;
                        } else {
                            end = mid - 1;
                        }
                    } else {//mid is in the second part
                        end = mid - 1;
                    }
                } else {//target is in the second part
                    if (nums[mid] >= nums[start] ) {//mid is in the first part
                        start = mid + 1;
                    } else {//mid is in the second part
                        if (target > nums[mid]) {
                            start = mid + 1;
                        } else {
                            end = mid - 1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};
