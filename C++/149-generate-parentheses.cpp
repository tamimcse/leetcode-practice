/*
https://leetcode.com/problems/generate-parentheses/
*/
class Solution {
    void generateParenthesis_inner(string s, int len, int start, int num_begin, int num_end,
                                   vector<string> &res) {
        if (start == len) {
            res.push_back(s);
            return;
        }
        
        if (num_begin < len/2) {
            s[start] = '(';
            generateParenthesis_inner(s, len, start + 1, num_begin + 1, num_end, res);            
        }

        if (num_begin > num_end) {
            s[start] = ')';
            generateParenthesis_inner(s, len, start + 1, num_begin, num_end + 1, res);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string s;
        s.resize(n << 1);
        vector<string> res;
        
        generateParenthesis_inner(s, n << 1, 0, 0, 0, res);
        return res;
    }
};
