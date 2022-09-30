/*
https://leetcode.com/problems/valid-anagram/
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26] = {0};
        
        for (auto &e : s) {
            hash[e - 'a']++;
        }
        
        for (auto &e : t) {
            hash[e - 'a']--;
        }
        
        for (int i = 0; i < 26; i++) {
            if (hash[i] != 0)
                return false;
        }
        return true;
    }
};
