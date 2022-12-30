/*
https://leetcode.com/problems/string-compression/
*/
class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0;
        int n = chars.size();
        char cur;
        int len;

        for (int i = 0; i < n;) {
            cur = chars[i];
            int j = i;
            while (j + 1 < n && chars[j+1] == chars[j]) {
                j++;
            }
            len = j - i + 1;
            chars[idx++] = cur;
            if (len > 1) {
                string str = to_string(len);
                for (int k = 0; k < str.length(); k++)
                    chars[idx++] = str[k];
            }
            i = j + 1;
        }
        return idx;
    }
};
