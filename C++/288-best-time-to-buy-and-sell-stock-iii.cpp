/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp1(n);
        vector<int> dp2(n);

        int min = prices[0];
        for (int i = 1; i < n; i++) {
            if (prices[i] - min > dp1[i-1])
                dp1[i] = prices[i] - min;
            else 
                dp1[i] = dp1[i-1];
            if (prices[i] < min)
                min = prices[i];
        }

        int max = prices[n-1];
        for (int i = n - 2; i >= 0; i--) {
            if (max - prices[i] > dp2[i+1])
                dp2[i] = max - prices[i];
            else
                dp2[i] = dp2[i+1];
            if (prices[i] > max)
                max = prices[i];
        }

        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            if (dp1[i] + dp2[i+1] > res)
                res = dp1[i] + dp2[i+1];
        }
        if (dp1[n-1] > res)
            res = dp1[n-1];

        return res;
    }
};
