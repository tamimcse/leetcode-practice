/*
https://leetcode.com/problems/regular-expression-matching/
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.length();
        int num_star = 0;
        vector<char> pat;
        vector<bool> ast;

        for (int i = 0; i < p.length(); i++) {
            pat.push_back(p[i]);
            if (i + 1 < p.length() && p[i + 1] == '*') {
                ast.push_back(true);
                i++;
            } else {
                ast.push_back(false);
            }
        }
        
        int pat_len = pat.size();
        vector<vector<int>> dp(pat_len);

        for (auto &e : dp)
            e.resize(s_len);

        reverse(pat.begin(), pat.end());
        reverse(ast.begin(), ast.end());
        reverse(s.begin(), s.end());

        dp[0][0] = s[0] == pat[0] || pat[0] == '.' ? 1 : 0;

        if (ast[0]) {
            for (int i = 1; i < s_len; i++) {
                if (s[i] == pat[0] || pat[0] == '.')
                    dp[0][i] = dp[0][i - 1];
                else
                    break;
            }
        }
        
        for (int i = 1; i < pat_len; i++) {
            string tmp;
            int num_char = 0;
            bool char_ast_found = false;
            bool other_char = false;
            for (int k = 0; k <= i; k++) {
                if (pat[k] == '.' || pat[k] == s[0]) {
                    if (!ast[k])
                        num_char++;
                    else
                        char_ast_found = true;
                } else if (!ast[k]) {
                    other_char = true;
                    break;
                }
            }
            if (other_char || num_char > 1) {
                dp[i][0] = 0;
            } else if (num_char == 1 || char_ast_found) {
                dp[i][0] = 1;
            } else {
                dp[i][0] = 0;
            }
        }

        for (int i = 1; i < pat_len; i++) {
            for (int j = 1; j < s_len; j++) {
                if (pat[i] == s[j]  || pat[i] == '.') {
                    if (dp[i-1][j-1])
                        dp[i][j] = 1;
                    else if (ast[i] && (dp[i][j-1] || dp[i-1][j]))
                        dp[i][j] = 1;
                } else {
                    if (ast[i] && dp[i-1][j])
                        dp[i][j] = 1;
                    else    
                        dp[i][j] = 0;
                }
            }
        }

        return dp[pat_len-1][s_len - 1] == 1;    
    }
};
