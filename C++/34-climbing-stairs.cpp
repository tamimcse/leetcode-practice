/*
https://leetcode.com/problems/climbing-stairs/
*/
class Solution {
   int memory[46] = {0};
public:
    int climbStairs(int n) {
        if (n == 0)
            return 1;
        if (!memory[n])
            memory[n] = climbStairs(n - 1) + ((n >= 2) ? climbStairs (n - 2) : 0);;
        return memory[n];
    }
};
