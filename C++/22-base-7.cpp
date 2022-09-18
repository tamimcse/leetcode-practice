/*
https://leetcode.com/problems/base-7/
*/

class Solution {
public:
    string convertToBase7(int num) {
        if (!num)
            return "0";
        bool is_neg = num < 0;
        if (is_neg)
            num = -num;
        int str_len = (log10 (num) / log10(7)) + 1 + (is_neg ? 1 : 0);
        string res(str_len, 0);
        
        int i = str_len - 1;
        while (num) {
            res[i] = (num % 7) + '0';
            num = num / 7;
            i--;
        }
        if (is_neg)
            res[0] = '-';
        return res;
    }
};
