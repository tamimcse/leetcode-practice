/*
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

Implement both naive solution and KMP. Note that, naive solution is also accepted by leetcode. I didn't implement KMP, because it only improves certain kinds of pattren (where many substrings of patten are prefix of pattern)
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length(), n = needle.length();

        for (int i = 0; i < m - n + 1; i++) {
            if (haystack[i] == needle[0]) {
                for (int j = 0; j < n; j++) {
                    if (haystack[i + j] == needle[j]) {
                        if (j == n - 1)
                            return i;
                    } else {
                        break;
                    }
                }
            }
        }
        return -1;
    }
};
