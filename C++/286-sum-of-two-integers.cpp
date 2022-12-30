/*
https://leetcode.com/problems/sum-of-two-integers/
*/
class Solution {
    int add (int a, int b) {
        long long sum = 0, carry = 0;
        long long lsb1, lsb2, bit_pos = 0, res;

        while (a || b || carry) {
            lsb1 = a & 1;
            lsb2 = b & 1;
            a = a >> 1;
            b = b >> 1;
            res = lsb1 ^ lsb2 ^ carry;
            carry = (lsb1 & lsb2) || (lsb1 & carry) || (lsb2 & carry) ? 1 : 0;
            sum = sum | (res << bit_pos);
            bit_pos++;
        }
        return sum;        
    }
    int sub (int a, int b) {
        long long sub = 0, borrow = 0;
        long long lsb1, lsb2, bit_pos = 0, res;

        while (a || b || borrow) {
            lsb1 = a & 1;
            lsb2 = b & 1;
            a = a >> 1;
            b = b >> 1;
            int tmp = lsb2;
            lsb2 = lsb2 ^ borrow;
            borrow = tmp & borrow;
            res = lsb1 ^ lsb2;
            if (!borrow && !lsb1 && lsb2)
                borrow = 1;
            if (!a && !b && bit_pos == 64)
                break;    
            sub = sub | (res << bit_pos);
            bit_pos++;
        }
        return sub;        
    }
public:
    int getSum(int a, int b) {
        if (a >= 0 && b >= 0)
            return add (a, b);
        else if (a < 0 && b < 0)
            return  -add(abs(a), abs (b));
        else if (b < 0)
            return sub (a, abs(b));
        else
            return sub (b, abs(a));
    }
};
