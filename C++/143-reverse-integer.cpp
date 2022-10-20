/*
https://leetcode.com/problems/reverse-integer/
*/
class Solution {
public:
    int reverse(int x) {
        bool neg = x < 0;
        unsigned int X = abs(x);

        unsigned int num = 0;
        while (X) {
            if (!neg && (num > INT_MAX/10 || (num == INT_MAX/10 && X % 10 > 7))) {
                return 0;
            }
            if (neg && (num > INT_MAX/10 || (num == INT_MAX/10 && X % 10 > 8))) {
                return 0;
            }
            num = num * 10 + X % 10;
            X = X/10;
        }

        return neg ? -num : num;
    }
};
