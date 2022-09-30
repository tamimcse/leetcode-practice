/*
https://leetcode.com/problems/longest-common-prefix/
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_len = strs[0].length();
        int smallest_str = 0;
        if (strs.size() == 1)
            return strs[0];
        
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i].length() < min_len) {
                smallest_str = i;
                min_len = strs[i].length();   
            }
        }
        
        int count = 0;
        for (int i = 0; i < strs[smallest_str].length(); i++) {
            for (auto e : strs) {
                if (e[i] != strs[smallest_str][i])
                    return strs[smallest_str].substr(0, count);
            }
            count++;
        }
        return strs[smallest_str].substr(0, count);
    }
};
