/*
https://leetcode.com/problems/repeated-substring-pattern/
*/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[0]) {
                string pat = s.substr(0, i);
                int start = i;
                int end = i + i - 1;
                //cout << pat << endl;
                while (end < s.length()) {
                    if (s.substr(start, i) == pat && end == s.length() - 1)
                        return true;
                    if (s.substr(start, i) == pat) {
                        start = end + 1;
                        end = start + i - 1;
                    } else {
                        break;
                    }
                }
            }
        }
        return false;
    }
};
