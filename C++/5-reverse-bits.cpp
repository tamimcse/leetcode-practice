/*
https://leetcode.com/problems/reverse-bits/
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t mask1 = 1U, mask2 = 1U << 31;
        while (mask2 > mask1) {
            if (n & mask1) {
                if ((n & mask2) == 0) {
                    n |= mask2;
                    n &= ~mask1;
                }
            } else {
                if (n & mask2) {
                    n |= mask1;
                    n &= ~mask2;
                }
            }
            mask1 <<= 1;
            mask2 >>= 1;
        }
        return n;
    }
};
