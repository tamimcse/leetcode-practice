/*
https://leetcode.com/problems/strobogrammatic-number/
*/
class Solution {
    bool is_mirror (char c1, char c2) {
        switch (c1) {
            case '6':
                return c2 == '9';
            case '9':
                return c2 == '6';
        }
        switch (c2) {
            case '6':
                return c1 == '9';
            case '9':
                return c1 == '6';
        }
        return false;
    }
public:
    bool isStrobogrammatic(string num) {
        for (int i = 0; i < num.length(); i++) {
            if ((num[i] >= '2' && num[i] <= '5') || num[i] == '7')
                return false;
        }
        
        if (num == "6" || num == "9")
            return false;
        
        for (int start = 0, end = num.length() - 1; end >= start; start++, end--) {
            if ((num[start] == '6' || num[end] == '6' || 
                 num[start] == '9' || num[end] == '9') &&
                !is_mirror (num[start], num[end]))
                return false;            
            if ((num[start] == '8' || num[end] == '8' || 
                 num[start] == '0' || num[end] == '0' ||
                 num[start] == '1' || num[end] == '1') &&
                num[start] != num[end])
                return false;
            if (end == start && (num[start] == '6' || num[start] == '9'))
                return false;
        }
        return true;
    }
};
