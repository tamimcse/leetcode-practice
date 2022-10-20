/*
https://leetcode.com/problems/powx-n/
*/
class Solution {
public:
    double myPow(double x, int n) {
        long N = n;
        bool neg = n < 0;
        double res;
        
        
        if (neg)
            N = -N;
        
        if (N == 0)
            return 1;
        if (N == 1)
            res = x;
        else if (N == 2)
            res = x * x;
        else {
            res = myPow(x, N/2);
            res = res * res;
            if (N & 1)
                res *= x;
        }
        
        if (neg)
            res = 1/res;
        return res;
    }
};
