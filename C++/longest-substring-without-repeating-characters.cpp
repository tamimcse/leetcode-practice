/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0, max_found = 0;
        int arr[256] = {0};
        
        for (end = 0; end < s.length(); end++) {
            if (!arr[s[end]]) {
                arr[s[end]] = 1;
                if (end - start + 1 > max_found)
                    max_found = end - start + 1;
            } else {
               while (1) {
                   if (s[start] == s[end]) {
                       start++;
                       break;
                   }
                   arr[s[start]] = 0;
                   start++;
               } 
            }
        }
        
        return max_found;
    }
};
