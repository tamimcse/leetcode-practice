/*
https://leetcode.com/problems/wildcard-matching/

Recursion + Memorization causes TLE.
*/



/************************************Recursion + Memorization*******************************************/
struct HashFunc {
    int operator () (const pair<string, string> &p) const {
        return p.first.length() + p.second.length();
    }
};

class Solution {

public:
    bool isMatch(string s, string p) {
        unordered_map<pair<string, string>, bool, HashFunc> hash;
        int g = 1;
        while (g < p.length()) {
            if (p[g] == '*' && p[g-1] == '*')
                p.erase(g, 1);
            else
                g++;    
        }

        return isMatch(s, p, hash);
    }
    bool isMatch(string s, string p, unordered_map<pair<string, string>, bool, HashFunc> &hash) {
        auto it = hash.find(make_pair(s, p));
        if (it != hash.end())
            return it->second;

        int s_len = s.length(), p_len = p.length();
        int s_start = 0, s_end = s_len - 1;
        int p_start = 0, p_end = p_len - 1;
        bool ret;

       cout << "s = " << s << " p = " << p << endl;

        if (p == "*")
            return true;

        if (s == "")
            return p == "";    

        if (p[p_start] == '*' && p[p_end] == '*') {
            vector<int> startIndices;
            vector<int> endIndices;

            for (int i = 0; i < s_len; i++) {
                if (p[p_start + 1] == '?' || s[i] == p[p_start + 1])
                    startIndices.push_back(i);
                if (p[p_end - 1] == '?' || s[i] == p[p_end - 1])
                    endIndices.push_back(i);
            }

            for (auto e1 : startIndices) {
                for (auto e2 : endIndices) {
                    if (e1 <= e2) {
                        ret = isMatch(s.substr(e1, e2 - e1 + 1), p.substr(1, p_len - 2));
                        hash[make_pair(s.substr(e1, e2 - e1 + 1), p.substr(1, p_len - 2))] = ret;
                        if (ret)
                            return true;
                    }
                }
            }
            return false;
        }    

        while (s_start < s_len && p_start < p_len) {
            if (p[p_start] == '*')
                break;
            if (p[p_start] != '?' && s[s_start] != p[p_start])
                return false;
            s_start++;
            p_start++;
        }

        if (s_start == s_len && p_start == p_len)
            return true;

        if (s_start == s_len || p_start == p_len)
            return (p_start == p_len - 1) && p[p_start] == '*';


        while (s_start <= s_end && p_start <= p_end) {
            if (p[p_end] == '*')
                break;
            if (p[p_end] != '?' && s[s_end] != p[p_end])
                return false;
            s_end--;
            p_end--;
        }

        if (s_start > s_end && p_start > p_end)
            return true;

        if (s_start > s_end || p_start > p_end)
            return p_end == p_start && p[p_end] == '*';

        ret =  isMatch(s.substr(s_start, s_end - s_start + 1),
                        p.substr(p_start, p_end - p_start + 1));
        hash[make_pair(s.substr(s_start, s_end - s_start + 1),
                        p.substr(p_start, p_end - p_start + 1))] = ret;
        return ret;                                 
    }
};
