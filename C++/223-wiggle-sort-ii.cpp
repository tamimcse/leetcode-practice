/*
https://leetcode.com/problems/wiggle-sort-ii/
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size(), secord_part_size = n/2;
        vector<int> res(n);
        
        sort(nums.begin(), nums.end());
        for (int i = 0, j = n - secord_part_size, k = 0; k < n; i++, j++) {
            res[k++] = nums[i];
            if (k < n)
                res[k++] = nums[j];
        }

        for (int i = 1; i < n; i++) {
            if (res[i] == res[i-1]) {
                int a1 = res[i-2];
                int a2 = res[i];
                int a3 = res[i+1];
                res[i-2] = a2;
                res[i-1] = a3;
                res[i] = a1;
                res[i+1] = a2;
                i = 0;
            }
        }

        nums = res;
    }
};
