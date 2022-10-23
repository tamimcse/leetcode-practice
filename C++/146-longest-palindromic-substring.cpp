/*
https://leetcode.com/problems/longest-palindromic-substring/
*/
class Solution {
    bool isPalindrome (string &s, int start, int end) {
        while (end > start) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
        
public:
    string longestPalindrome(string s) {
        unordered_map<char, vector<int>> hash;
        int max = 0;
        string res = "";
        
        if (s.length() <= 1)
            return s;
        
        for (int i = 0; i < s.length(); i++) {
            auto it = hash.find(s[i]);
            if (it != hash.end()) {
                for (int j = 0; j < hash[s[i]].size(); j++) {
                    if (i - hash[s[i]][j] + 1 > max && isPalindrome(s, hash[s[i]][j], i)) {
                        max = i - hash[s[i]][j] + 1;
                        res = s.substr(hash[s[i]][j], max);
                    }    
                }
            }
            hash[s[i]].push_back(i);
        }
        
        if (max == 0)
            res += s[0];
        return res;
    }
};
