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
        int num_digit = (log10(num) / log10(7)) + 1;
        int res_size = is_neg ? num_digit + 1 : num_digit;
        string res;
        res.resize(res_size);
        
        if (is_neg)
            res[0] = '-';
        int idx = res_size - 1;
        while (num) {
            res[idx--] = (num % 7) + '0';
            cout << (num % 7) << endl;
            num /= 7;
        }
        return res;
    }
};
