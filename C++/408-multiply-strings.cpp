/*
https://leetcode.com/problems/multiply-strings/
*/
class Solution {
    string add (string s1, string s2) {
        string res;
        int n1 = s1.length(), n2 = s2.length();
        int i = n1 - 1, j = n2 - 1;
        
        int carry = 0, sum = 0;
        while (i >= 0 || j >= 0) {
            int a = i >= 0 ? s1[i--] - '0' : 0;
            int b = j >= 0 ? s2[j--] - '0' : 0;
            sum = a + b + carry;
            res.insert(0, to_string(sum%10));
            carry = sum / 10;
        }
        if (carry)
            res.insert (0, to_string(carry));
        return res;
    }
    string multiply (string num, int digit) {
        int n = num.length();
        string res;
        
        int prod = 0, carry = 0;
        for (int i = n - 1; i >=0 ; i--) {
            int tmp = (digit * (num[i] - '0')) + carry;
            string to_insert;
            to_insert += to_string (tmp % 10);
            res.insert (0, to_insert);
            carry = tmp / 10;
        }
        if (carry)
            res.insert (0, to_string(carry));
        return res;
    }
public:
    string multiply(string num1, string num2) {
        int n1 = num1.length(), n2 = num2.length();
        vector<string> inners;
        
        for (int i = n2 - 1, j = 0; i >= 0; i--, j++) {
            string inner = multiply(num1, num2[i]-'0');
            for (int k = 0; k < j; k++)
                inner += "0";
            inners.push_back(inner);
        }
        
        string res = inners[0];
        for (int i = 1; i < inners.size(); i++) {
            res = add (res, inners[i]);
        }
        
        bool zero = true;
        for (int i = 0; i < res.length(); i++) {
            if (res[i] != '0') {
                zero = false;
                break;
            }
        }
        if (zero)
            return "0";
        
        return res;
    }
};
