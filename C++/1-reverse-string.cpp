/*
https://leetcode.com/problems/reverse-string/
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0, end = s.size() - 1;
        int tmp;
        
        while (end > start) {
            tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            start++;
            end--;
        }
    }
};
