/*
https://leetcode.com/problems/roman-to-integer/
*/
class Solution {
    int value (char c) {
        switch (c) {
            case 'I':  return 1;
            case 'V':  return 5;
            case 'X':  return 10;
            case 'L':  return 50;
            case 'C':  return 100;
            case 'D':  return 500;
            case 'M':  return 1000;
        }
        return -1;
    }
public:
    int romanToInt(string s) {
        int sum = value (s[s.length() - 1]);
        int prev = sum;
        
        for (int i = s.length() - 2; i >= 0; i--) {
            int curr = value(s[i]);
            if (curr >= prev)
                sum += curr;
            else 
                sum -= curr;
            prev = curr;
        }
        return sum;
    }
};
