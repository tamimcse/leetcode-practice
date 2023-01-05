/*
https://leetcode.com/problems/employee-free-time/
*/
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> res;
        vector<Interval> intervals;
        for (auto &employee : schedule) {
            for (auto &sched : employee) {
                intervals.push_back(sched);
            }
        }

        sort (intervals.begin(), intervals.end(), 
                [](Interval &a, Interval &b) {
            return a.start < b.start;
        });

        int y = intervals[0].end;
        int n = intervals.size();
        for (int i = 1; i < n; i++) {
            if (intervals[i].start > y) {
                res.push_back(Interval(y, intervals[i].start));
            }
            y = max (y, intervals[i].end);
        }
        return res;
    }
};
