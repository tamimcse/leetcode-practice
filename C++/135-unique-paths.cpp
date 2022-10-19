/*
https://leetcode.com/problems/unique-paths/
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m);
        
        for (int i = 0; i < m; i++) {
            dp[i].resize(n);
        }
        
        for (int i = 0; i < n; i++)
            dp[m-1][i] = 1;
        
        for (int i = 0; i < m; i++)
            dp[i][n-1] = 1;
        
        for (int x = m - 2; x >= 0; x--) {
            for (int y = n - 2; y >= 0; y--) {
                dp[x][y] = dp[x][y+1] + dp[x+1][y];
            }
        }
        
        return dp[0][0];
    }
};
