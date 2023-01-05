/*
https://leetcode.com/problems/course-schedule-iii/
*/
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();

        sort(courses.begin(), courses.end(), [](vector<int> &a, vector<int> &b) {
            if (a[1] != b[1])
                return a[1] < b[1];
            return a[0] < b[0];    
        });

        vector<int> intervals;
        int count = 0;
        int end = 0;
        for (int i = 0; i < n; i++) {
            if (end + courses[i][0] <= courses[i][1]) {
                count++;
                end = end + courses[i][0];
                intervals.push_back(courses[i][0]);
            } else {
                auto it = max_element(intervals.begin(), intervals.end());
                if (it != intervals.end() && *it > courses[i][0]) {
                    end = end - *it + courses[i][0];
                    intervals.erase(it);
                    intervals.push_back(courses[i][0]);
                }
            }
        }
        return count;
    }
};
