/*
https://leetcode.com/problems/is-subsequence/
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int to_find = 0;
        
        if (s == "")
            return true;
        
        for (int i = 0; i < t.length(); i++) {
            if (t[i] == s[to_find]) {
                to_find++;
                if (to_find == s.length())
                    return true;
            }
        }
        return false;
    }
};
