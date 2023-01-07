/*
https://leetcode.com/problems/count-pairs-in-two-arrays/

Quite interesting problem
*/
class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> diff(n);
        long count = 0;

        for (int i = 0; i < n; i++)
            diff[i] = nums1[i] - nums2[i];

        sort (diff.begin(), diff.end());

        for (int i = 0, start = n - 1; i < n; i++) {
            while (start > i && diff[i] + diff[start] > 0)
                start--;
            if (start <= i)
                count += (long)n - i - 1;
            else
                count += (long)n - start - 1;
        }
        return count;
    }
};
