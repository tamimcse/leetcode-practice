/*
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

Implement both naive solution and KMP
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length(), n = needle.length();

        for (int i = 0; i < m - n + 1;) {
            if (haystack[i] != needle[0]) {
                i++;
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (haystack[i + j] == needle[j]) {
                    if (j == n - 1)
                        return i;
                } else {
                    i++;
                    while (i < m && haystack[i] != needle[0])
                        i++;
                    break;
                }
            }
        }
        return -1;
    }
};
