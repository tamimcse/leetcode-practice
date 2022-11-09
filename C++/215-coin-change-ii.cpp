/*
https://leetcode.com/problems/coin-change-ii/

I found this pronblem quite hard
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        unordered_set<int> set;
        int n = coins.size();
        vector<vector<int>> dp(n);
        
        for (auto &e : dp) {
            e.resize(amount + 1);
        }
        
        sort (coins.begin(), coins.end());
        
        if (!amount || !n)
            return 1;
        
        for (int i = 1; i <= amount; i++) {
            if (i % coins[0] == 0)
                dp[0][i] = 1;
        }
        
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (j - coins[i] < 0)
                    dp[i][j] = dp[i - 1][j];
                else 
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
            }
        }
  
        return dp[n - 1][amount];
    }
};
