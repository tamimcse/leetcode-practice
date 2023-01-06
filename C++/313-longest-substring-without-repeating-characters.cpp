/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> set;

        int res = 0;
        for (int end = 0, start = 0; end < n; end++) {
            if (set.count(s[end]) == 0) {
                set.insert(s[end]);
            } else {
                while (start < end) {
                    if (s[start] == s[end]) {
                        start++;
                        break;
                    }
                    set.erase(s[start++]);
                }
            }
            res = max<long> (res, set.size());
        }
        return res;
    }
};
