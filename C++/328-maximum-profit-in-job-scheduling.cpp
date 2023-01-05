/*
https://leetcode.com/problems/maximum-profit-in-job-scheduling/

Intersting problem!!
*/
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int> indices(n);
        vector<int> dp(n);

        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        sort (indices.begin(), indices.end(), [&](int a, int b) {
            if (endTime[a] != endTime[b])
                return endTime[a] < endTime[b];
            return profit[a] > profit[b];
        });

        dp[0] = profit[indices[0]];
        for (int i = 1; i < n; i++) {
            if (startTime[indices[i]] >= endTime[indices[i-1]]) {
                dp[i] = dp[i-1] + profit[indices[i]];
            } else {
                int profit_before = 0;
                for (int j = i - 1; j >= 0; j--) {
                    if (endTime[indices[j]] <= startTime[indices[i]]) {
                        profit_before = dp[j];
                        break;
                    }
                }
                dp[i] = max (dp[i - 1], profit_before + profit[indices[i]]);
            }
        }

        return dp[n-1];
    }
};
