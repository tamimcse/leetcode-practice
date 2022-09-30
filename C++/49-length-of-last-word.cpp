/*
https://leetcode.com/problems/length-of-last-word/
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int i = len -1, end, start;
        while (i >= 0 && s[i] == ' ')
            i--;
        if (i < 0)
            return 0;
        
        end = i;
        start = i;
        while (start >= 0 && s[start] != ' ')
            start--;
        start++;
        return end - start + 1;
    }
};
