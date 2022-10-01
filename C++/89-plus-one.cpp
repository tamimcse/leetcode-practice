/*
https://leetcode.com/problems/plus-one/
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        
        for (int i = digits.size() - 1; i >= 0; i--) {
            int num = digits[i] + carry;
            digits[i] = num % 10;
            carry = num / 10;
        }
        if (carry) {
            digits.resize(digits.size() + 1);
            digits[0] = 1;
        }
        return digits;
    }
};
