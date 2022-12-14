/*
https://leetcode.com/problems/reverse-pairs/
*/
class Solution {
    void reversePairs(vector<int>& nums, int start, int end, int &count) {
        int to_insert;                  
        int mid = (start + end) >> 1;

        if (start == end)
            return;

        reversePairs (nums, start, mid, count);
        reversePairs (nums, mid + 1, end, count);

        for (int i = end, j = mid; (i >= mid + 1) && (j >= start);) {
            if (nums[j] > (long long)nums[i] * 2) {
                count += i - mid;
                j--;
            } else {
                i--;
            }
        }

        vector<int> tmp(end - start + 1);

        for (int i = 0, j = start, k = mid + 1; i < end - start + 1; i++) {
            if (j <= mid && k <= end) {
                if (nums[j] < nums[k]) {
                    tmp[i] = nums[j++]; 
                } else {
                    tmp[i] = nums[k++];
                }
            } else if (j <= mid) {
                tmp[i] = nums[j++];
            } else {
                tmp[i] = nums[k++];
            }
        }
        move(tmp.begin(), tmp.end(), nums.begin() + start);
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size(), count = 0;

        reversePairs(nums, 0, n - 1, count);

        return count;
    }
};
