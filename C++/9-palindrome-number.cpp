/*
https://leetcode.com/problems/palindrome-number/

Try without using temporary array
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x >= 0 && x <= 9)
            return true;
        
        if (x % 10 == 0)
            return false;
        
        int half = 0;
        while (half <= x) {
            if ((half && half == (x / 10)) || half == x)
                return true;
            half = half * 10 + x % 10;
            x /= 10;
        }
        return false;
    }
};
