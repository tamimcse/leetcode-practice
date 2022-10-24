/*
https://leetcode.com/problems/restore-ip-addresses/
*/
class Solution {
    bool valid(string s) {
        if (s == "0")
            return true;
        if (s[0] == '0')
            return false;
        int a = atoi(s.c_str());
        return a >= 1 && a <= 255;
    }
    void restoreIpAddresses_inner(string s, int s_idx, string &tmp, int tmp_idx, int count,
                                  vector<string> &res) {
        if (count == 3) {
            if (valid(s.substr(s_idx))) {
                tmp += s.substr(s_idx);
                res.push_back(tmp);
            }
            return;
        }
        
        for (int i = 1; (i <= 3) && (s_idx + i < s.length()); i++) {
            string cur = s.substr(s_idx, i);
            if (!valid(cur))
                continue;
            tmp += s.substr(s_idx, i);
            tmp += '.';
            restoreIpAddresses_inner(s, s_idx + i, tmp, tmp_idx + i + 1, count + 1, res);
            tmp.erase(tmp_idx);
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string tmp;
        int count = 0;
        int s_idx = 0, tmp_idx = 0;
        
        restoreIpAddresses_inner(s, 0, tmp, 0, 0, res);
        return res;
    }
};
