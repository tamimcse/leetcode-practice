/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

Very very very interesting problem!!!!
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp (k, vector<int>(n));

        int min_found = prices[0];
        for (int i = 1; i < n; i++) {
            dp[0][i] = max (dp[0][i-1], prices[i] - min_found);
            min_found = min (min_found, prices[i]);
        }

        for (int i = 1; i < k; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j];
                dp[i][j] = max (dp[i][j], dp[i][j-1]);
                if (prices[j] < prices[j-1])
                    continue;
                for (int m = 1; m < j; m++) {
                    dp[i][j] = max (dp[i][j], dp[i-1][m] + 
                                    prices[j] - prices[m]);
                }
            }
        }
        return dp[k-1][n-1];
    }
};
