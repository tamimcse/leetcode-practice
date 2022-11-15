/*
https://leetcode.com/problems/decode-ways/
*/
class Solution {
    bool is_valid_two_chars (string s) {
        int sum = 0;
        
        if (s[0] == '1' || s[0] == '2') {
            sum = (s[0] - '0') * 10 + (s[1] - '0');
            return sum >= 1 && sum <= 26;
        } else {
            return false;
        }
    }
public: 
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n);
        
        
        if (n > 0 && s[n-1] != '0')
            dp[n-1] = 1;
        if (n >= 2) {
            if (s[n-2] != '0')
                dp[n-2] = dp[n-1];
            if (is_valid_two_chars(s.substr(n-2)))
                dp[n-2]++;
        }
        
        for (int i = n - 3; i >= 0; i--) {
            if (s[i] != '0' && dp[i+1]) {
                dp[i] += dp[i+1];
            }
            
            if (dp[i+2] && is_valid_two_chars(s.substr(i, 2))) {
                dp[i] += dp[i+2];
            }
        }
        
        return dp[0];
    }
};
