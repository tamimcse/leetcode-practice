/*
https://leetcode.com/problems/palindrome-partitioning/

Very interesting problem!!
*/
class Solution {
    bool is_palindrome(string s) {
        int n = s.length();

        for (int i = 0, j = n - 1; i < j; i++, j-- ) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        deque<vector<vector<string>>> dp(n);

        dp[n-1].push_back({{s[n-1]}});
        for (int i = n - 2; i >= 0; i--) {
            vector<vector<string>> prev = dp[i+1];
            for (auto &e : prev) {
                string tmp = "";
                tmp += s[i];
                e.push_back(tmp);
            }
            string substr = s.substr(i);
            if (is_palindrome(substr)) {
                prev.push_back({substr});
            }
            for (int j = i + 1; j < n - 1; j++) {
                string substr = s.substr(i, j - i + 1);
                if (is_palindrome(substr)) {
                    vector<vector<string>> tmp = dp[j+1];
                    for (auto &e : tmp)
                        e.push_back(substr);
                    move (tmp.begin(), tmp.end(), back_inserter(prev));
                }
            }
            dp[i] = move(prev);
        }
        for (auto &e : dp[0] ) {
            reverse (e.begin(), e.end());
        }
        return dp[0];
    }
};
