/*
https://leetcode.com/problems/confusing-number/
*/
class Solution {
public:
    bool confusingNumber(int n) {
        int tmp = n;
        
        if (n == 0 || n == 1 || n == 8)
            return false;
        if (n == 6 || n == 9)
            return true;
        
        int new_num = 0, digit, pos = 0;
        while (tmp) {
            digit = tmp % 10;
            if (digit == 2 || digit == 3 || digit == 4 || digit == 5 || digit == 7)
                return false;
            if (digit == 6)
                digit = 9;
            else if (digit == 9)
                digit = 6;
            new_num = new_num * 10 + digit;
            pos++;
            tmp /= 10;
        }
        cout << new_num;
        return new_num != n;
    }
};
