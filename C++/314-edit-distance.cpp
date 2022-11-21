/*
https://leetcode.com/problems/edit-distance/
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word2.length(), n = word1.length();
        vector<vector<int>> dp(m);
        
        if (word2.length() == 0)
            return word1.length();
        if (word1.length() == 0)
            return word2.length();
        
        for (auto &e : dp)
            e.resize(n);
        
        dp[0][0] = word1[0] == word2[0] ? 0 : 1;
        for (int i = 1; i < n; i++) {
            dp[0][i] = word2[0] == word1[i] ? i : dp[0][i-1] + 1;
        }
        for (int i = 1; i < m; i++) {
            dp[i][0] = word2[i] == word1[0] ? dp[i-1][0] : dp[i-1][0] + 1;
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int cur = min(dp[i-1][j], dp[i][j-1]) + 1;
                if (word2[i] == word1[j])
                    cur = min (cur, dp[i-1][j-1]);
                else
                    cur = min (cur, dp[i-1][j-1] + 1);
                dp[i][j] = cur;
            }
        }
        return dp[m-1][n-1];
    }
};
