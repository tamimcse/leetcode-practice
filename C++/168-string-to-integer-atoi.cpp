/*
https://leetcode.com/problems/string-to-integer-atoi/
*/
class Solution {
public:
    int myAtoi(string s) {
        int len = s.length();
        long long sum;
        bool positive;
        
        for (int i = 0; i < len; i++) {
            if (s[i] != ' ') {
                if (i) {
                    s.erase(0, i);
                }
                break;
            }
        }
        
        if (s[0] == '+' || isdigit(s[0]))
            positive = true;
        else
            positive = false;
        
        if (s[0] == '+' || s[0] == '-') {
            s.erase(0, 1);       
        }

        len = s.length();
        for (int i = 0; i < len; i++) {
            if (!isdigit(s[i])) {
                s.erase(i);
                break;
            }
        }
        
        cout << s << endl;
        
        len = s.length();
        sum = 0;
        for (int i = 0; i < len; i++) {
            sum = sum * 10 + (s[i] - '0');
            if (positive && sum > (pow(2, 31) - 1))
                return pow(2, 31) - 1;
            if (!positive && -sum < (-pow(2, 31)))
                return -pow(2, 31);
        }
        
        if (!positive)
            sum = -sum;
        
        return sum;
    }
};
