/*
https://leetcode.com/problems/license-key-formatting/
*/
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int num_chars = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '-')
                num_chars++;
        }
        
        if (!num_chars)
            return "";
        
        int num_groups = ceil((float)num_chars/k);
        int num_first_group = (num_chars % k == 0) ? k : num_chars % k;
        
        int res_len = num_first_group + (num_groups - 1) * (k + 1);
        string res;
        res.resize(res_len);
        
        int idx = 0, i = 0;
        while (num_first_group > 0) {
            if (s[i] == '-') {
                i++;
                continue;
            }
            res[idx++] = s[i++];
            num_first_group--;
        }
        
        for (int m = 0; m < num_groups - 1; m++) {
            res[idx++] = '-';
            int count = k;
            while (count > 0) {
                if (s[i] == '-') {
                    i++;
                    continue;
                }
                res[idx++] = s[i++];
                count--;
            }
        }

        for (int j = 0; j < res.length(); j++) {
            if (islower(res[j])) {
                res[j] = toupper(res[j]);
            }
        }
        return res;
    }
};
