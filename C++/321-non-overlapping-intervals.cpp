/*
https://leetcode.com/problems/non-overlapping-intervals/
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0;

        sort (intervals.begin(), intervals.end(), [](vector<int> &v1, vector<int> &v2) {
            return v1[0] < v2[0];
        });

        int y = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < y) {
                y = min (y, intervals[i][1]);
                count++;
            } else {
                y = intervals[i][1];
            }
        }
        return count;
    }
};
