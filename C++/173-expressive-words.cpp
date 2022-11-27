/*
https://leetcode.com/problems/expressive-words/
*/
class Solution {
    bool isStretchy(string orig, string stretchy) {
        int n = orig.length(), m = stretchy.length();
        
        if (orig[0] != stretchy[0])
            return false;
        
        char prev = orig[0];
        int prev_count = 1;
        int i = 1, j = 1;
        for (; i < n ; i++, j++) {
            if (j >= m)
                return false;
            if (orig[i] == stretchy[j]) {
                if (orig[i] == prev) {
                    prev_count++;
                } else {
                    prev = orig[i];
                    prev_count = 1;
                }
            } else {
                if (stretchy[j-1] != stretchy[j])
                    return false;
                while (j < m && stretchy[j-1] == stretchy[j]) {
                    j++;
                    prev_count++;
                }
                if (prev_count < 3)
                    return false;
                else {
                    i--;
                    j--;
                }
            }
        }
        
        if (j < m) {
            while (j < m && stretchy[j-1] == stretchy[j]) {
                j++;
                prev_count++;
            }
            return prev_count >= 3 && j == m;
        } else {
            return true;
        }
    }
public:
    int expressiveWords(string s, vector<string>& words) {
        int count = 0;
        
        for (auto &e : words) {
            if (isStretchy(e, s)) {
                count++;
            }                
        }
        return count;
    }
};
