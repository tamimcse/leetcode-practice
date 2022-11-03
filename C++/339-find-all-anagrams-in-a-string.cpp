/*
https://leetcode.com/problems/find-all-anagrams-in-a-string/
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.length(), n = p.length(), start = 0, end = 0;
        int hash[26] = {0};
        vector<int> res;
        
        for (int i = 0; i < n; i++) {
            hash[p[i] - 'a']++;
        }
        
        while (end < m) {
            if (hash[s[end] - 'a']) {
                hash[s[end] - 'a']--;
                if (end - start + 1 == n) {
                    res.push_back(start);
                    hash[s[start] - 'a']++;
                    start++;
                    end++;
                } else {
                    end++;    
                }
            } else {
                hash[s[start] - 'a']++;
                start++; 
            }
        }
        return res;
    }
};
