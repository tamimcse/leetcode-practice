/*
https://leetcode.com/problems/palindrome-number/

Try without using temporary array
*/
class Solution {
public:
    bool isPalindrome(int x) {
        int first = x, second = 0;
            
        if (x < 0)
            return false;
        
        if (x >= 0 && x <= 9)
            return true;
        
        if (x % 10 == 0)
            return false;
        
        while (second < first) {
            int last_digit = first % 10;
            first = first / 10;
            second = second * 10 + last_digit;
        }
        
        return (first == second) || ((second / 10) == first);
    }
};
