/*
https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
*/
class Solution {
    bool can_form (string s, unordered_map<char, int> hash) {
        for (int i = 0; i < s.length(); i++) {
            auto it = hash.find(s[i]);
            if (it == hash.end())
                return false;
            if (it->second == 1)
                hash.erase(s[i]);
            else
                hash[s[i]]--;
        }
        return true;
    }
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> hash;
        int res = 0;

        for (int i = 0; i < chars.length(); i++)
            hash[chars[i]]++;

        for (auto &s : words) {
            if (can_form(s, hash)) {
                res += s.length();
            }
        }
        return res;
    }
};
