/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0], max = prices[0], profit = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < max) {
                profit += max - min;
                min = prices[i];
                max = prices[i];
            } else if (prices[i] < min) {
                min = prices[i];
                max = prices[i];
            } else if (prices[i] > max) {
                max = prices[i];
            }
        }
        profit += max - min;
        return profit;
    }
};
