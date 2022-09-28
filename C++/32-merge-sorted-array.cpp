/*
https://leetcode.com/problems/merge-sorted-array/
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1 = m - 1, idx2 = n - 1, to_insert = m + n - 1;
        while (idx1 >= 0 || idx2 >= 0) {
            if (idx1 < 0)
                nums1[to_insert--] = nums2[idx2--];
            else if (idx2 < 0)
                nums1[to_insert--] = nums1[idx1--];
            else if (nums1[idx1] >= nums2[idx2])
                nums1[to_insert--] = nums1[idx1--];
            else 
                nums1[to_insert--] = nums2[idx2--];
        }
    }
};
