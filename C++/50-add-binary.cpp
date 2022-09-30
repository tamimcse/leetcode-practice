/*
https://leetcode.com/problems/add-binary/
*/
class Solution {
public:
    string addBinary(string a, string b) {
        int max_len = max (a.length(), b.length());
        string res;
        res.resize(max_len);
        int carry = 0;
        
        for (int i = a.length() - 1, j = b.length() - 1, res_idx = max_len - 1; 
             i >= 0 || j >= 0; i--, j--, res_idx--) {
            int ch1 = i >= 0 ? a[i] - '0' : 0;
            int ch2 = j >= 0 ? b[j] - '0' : 0;
            res[res_idx] =  (ch1 ^ ch2 ^ carry) + '0';
            carry = (ch1 + ch2 + carry) >= 2 ? 1 : 0;
        }
        cout << res;
        if (carry) {
            res = '1' + res;
        }
        return res;
    }
};
