/*
https://leetcode.com/problems/palindromic-substrings/
*/
class Solution {
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        
        for (; i < j; i++, j--) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }

public:
    int countSubstrings(string s) {
        int count = 0, n = s.length();
                
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome (s.substr(i, j - i + 1)))
                    count++;
            }
        }
        return count;
    }
};
