/*
https://leetcode.com/problems/maximum-value-after-insertion/
*/
class Solution {
    string max(string s, int x) {
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            if (x > (s[i] - '0')) {
                s.insert(i, to_string(x));
                return s;
            }
        }
        
        s += to_string(x);
        return s;
    }
    string min(string s, int x) {
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            if (x < (s[i] - '0')) {
                s.insert(i, to_string(x));
                return s;
            }
        }
        
        s += to_string(x);
        return s;
    }
public:
    string maxValue(string n, int x) {
        if (n[0] == '-') {
            string s = "-";
            return s + min(n.substr(1), x);
        } else {
            return max(n, x);
        }
    }
};
