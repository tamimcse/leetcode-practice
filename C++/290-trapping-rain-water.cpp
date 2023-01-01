/*
https://leetcode.com/problems/trapping-rain-water/
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        int start = 0;

        for (int i = 1; i < n; i++) {
            if (height[i] >= height[start]) {
                for (int j = start + 1; j < i; j++) {
                    res +=  height[start] - height[j];
                }
                start = i;
            }
        }

        if (start != n - 1) {
            vector<int> rest (height.begin() + start, height.end());
            reverse (rest.begin(), rest.end());
            res += trap (rest);
        }

        return res;
    }
};
