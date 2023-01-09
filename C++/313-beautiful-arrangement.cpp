/*
https://leetcode.com/problems/beautiful-arrangement/

Very common problem in the interview!!!

You need to check why DP gets TLE and backtacking doesn't.
*/

/***This gets TLE**********************************/
class Solution {
    bool isBeautiful (int idx, int val) {
        return val % idx == 0 || idx % val == 0;
    }
public:
    int countArrangement(int n) {
        vector<vector<unordered_set<int>>> dp(n+1);

        vector<unordered_set<int>> v;
        for (int i = 1; i <= n; i++) {
            if (isBeautiful (i, n)) {
                v.push_back({i});
            }
        }
        dp[n] = v;
        for (int i = n - 1; i >= 1; i--) {
            for (int j = 1; j <= n; j++) {
                if (isBeautiful (j, i)) {
                    for (auto e : dp[i+1]) {
                        if (e.count(j) == 0) {
                            unordered_set<int> s = e;
                            s.insert(j);
                            dp[i].push_back(s);
                        }
                    }
                }
            }
        }
        return dp[1].size();
    }
};

/******This solution works!!!!!!************************/
class Solution {
    bool isBeautiful (int idx, int val) {
        return val % idx == 0 || idx % val == 0;
    }

    void countArrangement(int n, int start, unordered_set<int> &s,
                            int &count) {
        if (s.size() == n) {
            count++;
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (isBeautiful (i, start) && s.count(i) == 0) {
                s.insert(i);
                countArrangement (n, start + 1, s, count);
                s.erase(i);
            }
        }
    }
public:
    int countArrangement(int n) {
        unordered_set<int> s;
        int count = 0;

        countArrangement (n, 1, s, count);
        return count;
    }
};
