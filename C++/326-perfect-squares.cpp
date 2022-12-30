/*
https://leetcode.com/problems/perfect-squares/
*/
class Solution {
    bool isperfectSqr (int n) {
        int s = sqrt(n);

        return s * s == n;
    }
public:
    int numSquares(int n) {
        if (isperfectSqr(n))
            return 1;

        vector<int> dp(n+1);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (isperfectSqr(i)) {
                dp[i] = 1;
                cout << dp[i] << " ";
                continue;
            }
            int min_options = INT_MAX;
            int max_sqrt = sqrt (i);
            for (int j = max_sqrt; j >= 1; j--) {
                min_options = min (min_options, dp[j*j] + dp[i-j*j]);
            }
            dp[i] = min_options;
        }
        return dp[n];
    }
};
