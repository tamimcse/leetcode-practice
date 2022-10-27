/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/
class Solution {
        vector<vector<char>> map = {
            {' '},
            {},
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'},
        };
    void letterCombinations_inner(string digits, int idx, 
                                  string &cur, vector<string> &res) {
        if (idx == digits.size()) {
            res.push_back(cur);
            return;
        }        
        
        for (auto ch : map[digits[idx] - '0']) {
            cur[idx] = ch;
            letterCombinations_inner(digits, idx + 1, cur, res);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string cur;
        cur.resize(digits.size());
        
        if (digits == "")
            return res;
            
        letterCombinations_inner(digits, 0, cur, res);
        return res;
    }
};
