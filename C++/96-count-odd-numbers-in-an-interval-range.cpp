/*
https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
*/
class Solution {
public:
    int countOdds(int low, int high) {
        if ((low & 1) == 0)
            low++;
        if ((high & 1) == 0)
            high--;
        if (high < low)
            return 0;
        else
            return ((high - low) >> 1) + 1;
    }
};
