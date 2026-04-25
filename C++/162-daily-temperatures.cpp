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

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());

        res[res.size() - 1] = 0;
        int maxIdx = res.size() - 1;
        for (int i = res.size() - 2; i >= 0; i--) {
            if (temperatures[i] < temperatures[i+1]) {
                res[i] = 1;
                maxIdx = i;
            } else {
                for (int j = maxIdx; j < res.size(); j++) {
                    if (temperatures[j] > temperatures[i]) {
                        res[i] = j - i;
                        break;
                    }
                }
            }
        }
        return res;
    }
};
