/*
https://leetcode.com/problems/backspace-string-compare/
*/
class Solution {
    void final_string(string &s) {
        int to_insert = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '#') {
                if (to_insert > 0)
                    to_insert--;
            } else {
                s[to_insert++] = s[i];
            }
        }
        s.replace(to_insert, s.length() - to_insert, "");        
    }
public:
    bool backspaceCompare(string s, string t) {
        final_string(s);
        cout << s << endl;
        final_string(t);
        cout << t << endl;
        return s == t;
    }
};
