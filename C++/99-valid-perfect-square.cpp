/*
https://leetcode.com/problems/valid-perfect-square/
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1)
            return true;
        long start = 1, end = num >> 1, mid;
        
        while (end >= start) {
            mid = (start + end) >> 1;
            if (mid * mid == num)
                return true;
            if (mid * mid > num)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return false;
    }
};
