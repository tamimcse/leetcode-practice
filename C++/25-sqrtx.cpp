/*
https://leetcode.com/problems/sqrtx/
*/
class Solution {
public:
    int mySqrt(int x) {
        int start = 0, end = x / 2, mid;
        if (x < 2)
            return x;
        long long n1, n2;
        while (end >= start) {
            mid = (start + end) >> 1;
            n1 = (long long)mid * mid;
            n2 = (long long)(mid + 1) * (mid + 1);
            if (n1 <= x && (x < n2)) {
                return mid;
            } else if (n1 < x) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return mid;
    }
};
