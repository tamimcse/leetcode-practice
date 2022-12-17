/*
https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/

Actual problem was:

https://www.geeksforgeeks.org/interesting-method-generate-binary-numbers-1-n/
*/


/*******This gets TLE******************************/

class Solution {
    vector<string> getBinStr(int n) {
        vector<string> res;
        string s = "1";

        res.push_back(s);
        for (int i = 1; i < n; i++) {
            if ((i & 1) == 0) {
                s[s.length() - 1] = '1';
            } else {
                int num = ((i ^ (i + 1)) >> 1) + 1;
                int count = log10(num) / log10(2);
                if (s.length() == count) {
                    s.insert(0, "1");
                }
                s[s.length() - count - 1] = '1';
                for (int k = s.length() - count; k < s.length(); k++) {
                    s[k] = '0';
                }
            }
            res.push_back(s);
        }
        return res;
    }
public:
    bool queryString(string s, int n) {
        int m = s.length();
        vector<string> pat = getBinStr(n);

        for (auto &e : pat) {
            if (s.find(e) == string::npos)
                return false;
        }
        return true;
    }
};
