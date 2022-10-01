/*
https://leetcode.com/problems/power-of-three/

Do it both using loop and without loop.
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (!n)
            return false;
        
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};
