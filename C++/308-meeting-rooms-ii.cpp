/*
https://leetcode.com/problems/meeting-rooms-ii/

Interesting problem!!!!
*/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int res = 1;

        sort (intervals.begin(), intervals.end(), [](vector<int> &v1, vector<int> &v2) {
            return v1[0] < v2[0];
        });

        for (int i = 1; i < n; i++) {
            int cur = 1;
            for (int j = 0; j < i; j++) {
                if (intervals[i][0] < intervals[j][1])
                    cur++;
            }
            res = max (res, cur);
        }
        return res;
    }
};
