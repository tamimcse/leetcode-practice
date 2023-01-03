/*
https://leetcode.com/problems/merge-intervals/
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;

        sort (intervals.begin(), intervals.end(), [](vector<int> &v1, vector<int> &v2) {
            return v1[0] < v2[0];
        });

        int x = intervals[0][0], y = intervals[0][1]; 
        for (int i = 1; i < n; i++) {
            if (y < intervals[i][0]) {
                res.push_back({x, y});
                x = intervals[i][0];
                y = intervals[i][1];
            }
            y = max (y, intervals[i][1]);    
        }
        res.push_back({x, y});
        return res;
    }
};
