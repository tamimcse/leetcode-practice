/*
https://leetcode.com/problems/counting-bits/

Do it it O(n) without using __builtin_popcount()

Look at approach 4 if needed
*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res (n + 1);
        
        int num = 0;
        res[0] = 0;
        for (int i = 1; i <= n; i++) {
            res[i] = res[i & (i - 1)] + 1;
        }
        return res;
    }
};
