/*
https://leetcode.com/problems/meeting-rooms-iii/
*/
class Solution {
        int getFreeRoom(vector<long> &freetime, int startTime) {
            int n = freetime.size();
            int min_idx = 0;

            for (int i = 0; i < n; i++) {
                if (freetime[i] <= startTime)
                    return i;
                if (freetime[i] < freetime[min_idx])
                    min_idx = i;    
            }
            return min_idx;
        }
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> rooms(n);
        vector<long> freetime(n);

        sort (meetings.begin(), meetings.end(),
                [](vector<int> &m1, vector<int> &m2) {
            return m1[0] < m2[0];
        });    

        for (auto &m : meetings) {
            int room_no = getFreeRoom (freetime, m[0]);
            rooms[room_no]++;
            if (freetime[room_no] <= m[0])
                freetime[room_no] = m[1];
            else
                freetime[room_no] += (long)m[1] - m[0];
        }

        int res = 0;
        for (int i = 1; i < n; i++) {
            if (rooms[i] > rooms[res])
                res = i;
        }
        return res;
    }
};
