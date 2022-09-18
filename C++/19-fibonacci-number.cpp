/*
https://leetcode.com/problems/fibonacci-number/
*/
class Solution {
public:
    int fib(int n) {
        deque<int> lastTwo(2); 
        lastTwo[0] = 0; 
        lastTwo[1] = 1;
        
        if (n >= 0 && n <= 1)
            return n;
        
        for (int i = 2; i <= n; i++) {
            lastTwo.push_back(lastTwo[0] + lastTwo[1]);
            lastTwo.pop_front();
        }
        
        return lastTwo[1];
    }
};
