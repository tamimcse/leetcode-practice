/*
https://leetcode.com/problems/coin-change/
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int *dp = new int[amount + 1]();
        
        sort(coins.begin(), coins.end());
        
        for (auto e : coins) {
            if (e <= amount)
                dp[e] = 1;
        }
        
        for (int i = 1; i <= amount; i++) {
            if (dp[i])
                continue;
            int num = INT_MAX;
            for (int j = 0; j < n && coins[j] < i; j++) {
                if (dp[i - coins[j]] > 0) {
                    num = min (dp[i - coins[j]] + 1, num);
                }
            }
            dp[i] = num == INT_MAX ? -1 : num;
        }
        
        return dp[amount];
    }
};
