/*
https://leetcode.com/problems/insert-interval/
*/
class Solution {
    bool doesOverlap(vector<int>& int1, vector<int>& int2) {
        return !(int2[0] > int1[1] || int1[0] > int2[1]);
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval[1] < intervals[i][0]) {
                intervals.insert(intervals.begin() + i, newInterval);
                return intervals;
            }
            if (doesOverlap(intervals[i], newInterval)) {
                intervals[i][0] = min (intervals[i][0], newInterval[0]);
                intervals[i][1] = max (intervals[i][1], newInterval[1]);
                while (i + 1 < intervals.size() &&
                       doesOverlap(intervals[i], intervals[i+1])) {
                    intervals[i][1] = max (intervals[i][1], intervals[i+1][1]);
                    intervals.erase(intervals.begin() + i + 1);
                }
                return intervals;   
            }
        }
        intervals.push_back(newInterval);
        return intervals;
    }
};
