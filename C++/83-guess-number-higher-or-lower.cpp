/*
https://leetcode.com/problems/guess-number-higher-or-lower/
*/
class Solution {
public:
    int guessNumber(int n) {
        long start = 1, end = n, mid;
        
        while (end >= start) {
            mid = (start + end) >> 1;
            int res = guess (mid);
            if (!res)
                return mid;
            if (res == -1)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return -1;
    }
};
