/*
https://leetcode.com/problems/longest-common-subsequence/
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m);
        
        for (auto &e : dp)
            e.resize(n);
        
        if(text1[0] == text2[0])
            dp[0][0] = 1;
        for (int i = 1; i < n; i++) {
            dp[0][i] = text2[i] == text1[0] ? 1 : dp[0][i-1];
        }
        for (int i = 1; i < m; i++) {
            dp[i][0] = text1[i] == text2[0] ? 1 : dp[i-1][0];
        }
        
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int cur = 0;
                if (text1[i] == text2[j]) {
                    cur = dp[i-1][j-1] + 1;
                }
                cur = max (cur, dp[i-1][j]);
                cur = max (cur, dp[i][j-1]);
                dp[i][j] = cur;
            }
        }
        return dp[m-1][n-1];
    }
};
