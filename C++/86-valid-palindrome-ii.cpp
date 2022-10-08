/*
https://leetcode.com/problems/valid-palindrome-ii/
*/
class Solution {
    bool isalindrome(string s) {
        int start = 0, end = s.length() - 1;
        
        while (end > start) {
            if (s[start] == s[end]) {
                start++;
                end--;
            } else { 
                return false;
            }
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int start = 0, end = s.length() - 1;
        
        while (end > start) {
            if (s[start] == s[end]) {
                start++;
                end--;
            } else { 
                return isalindrome(s.substr(start, end - start)) || isalindrome(s.substr(start + 1, end - start));
            }
        }
        return true;
    }
};
