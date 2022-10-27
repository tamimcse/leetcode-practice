/*
https://leetcode.com/problems/daily-temperatures/
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> q;
        pair<int, int> cur;
        vector<int> res(temperatures.size());
        
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while (!q.empty()) {
                cur = q.top();
                if (temperatures[i] < cur.first) {
                    res[i] = cur.second - i;
                    q.push(make_pair(temperatures[i], i));
                    break;
                } else {
                    q.pop();
                }
            }
            if (!res[i]) {
                q.push(make_pair(temperatures[i], i));
            }
        }
        
        return res;
    }
};
