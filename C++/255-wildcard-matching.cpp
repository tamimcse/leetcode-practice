/*
https://leetcode.com/problems/wildcard-matching/

*/
class Solution {

public:
    bool isMatch(string s, string p) {
        for (int i = 1; i < p.length();) {
            if (p[i] == '*' && p[i-1] == '*')
                p.erase(i, 1);
            else
                i++;    
        }

        if (p == "*" || s == p)
            return true;

        int s_len = s.length(), p_len = p.length();
        vector<vector<int>> dp(p_len);

        if (s_len == 0 || p_len == 0)
            return false;

        for (auto &e : dp)
            e.resize(s_len);

        dp[0][0] = s[0] == p[0] || p[0] == '?' ? 1 : 0;    
        if (p[0] == '*') {
            for (int i = 0; i < s_len; i++) {
                dp[0][i] = 1;
            }
        }

        if (p[1] == '*')
            dp[1][0] = dp[0][0];
        else if ((p[1] == s[0] || p[1] == '?') && p[0] == '*')
            dp[1][0] = 1;

        if (p[2] == '*')
            dp[2][0] = dp[1][0];        

        for (int i = 1; i < p_len; i++) {
            for (int j = 1; j < s_len; j++) {
                if (p[i] == s[j] || p[i] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if (p[i] == '*') {
                    if (dp[i-1][j-1] || dp[i][j-1] || dp[i-1][j])
                        dp[i][j] = 1;
                }   
            }
        }

        return dp[p_len-1][s_len-1] == 1;
    }
};
